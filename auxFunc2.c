#include "holberton.h"
/**
 * str_concat - function tht concatenate two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: char.
 */
char *str_concat(char *s1, char *s2)
{
	int i, len1 = 0, len2 = 0;
	char *strcat;

	for (; s1[len1] != '\0'; len1++)
		;
	for (; s2[len2] != '\0'; len2++)
		;
	strcat = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!strcat)
		return (NULL);
	for (i = 0; s1[i] != '\0'; i++)
		strcat[i] = s1[i];
	for (i = 0; s2[i] != '\0'; i++)
		strcat[len1 + i] = s2[i];
	strcat[len1 + len2] = '\0';
	return (strcat);
}
/**
 * status - check if exist the file p
 * @p: the command to check if exist
 * @string: the environ variable PATH
 * @length: number of different paths
 * Return: the absolute path to the command, if it not exist return NULL
 */
char *status(char *p, char **string, int length)
{
	char *aux =  "/", *aux2;
	int i = 0;

	aux = str_concat(aux, p);
	while (i < length)
	{
		aux2 = str_concat(string[i], aux);
		if (stat(aux2, &st) == 0)
		{
			free(aux);
			return (aux2);
		}
		else
			free(aux2);
		i++;
	}
	free(aux);
	return (NULL);
}
/**
 * _free - function that frees the variable
 * @cadena: what was entered by the user
 * @string: the path and arguments to execute
 * @command: the environ variable PATH
 */
void _free(char *cadena, char **string, char **command)
{
	free(cadena);
	free(string);
	free(command);
}
/**
 * execute - function execute the command
 * @com: path that content the command
 * @s: string that content the path and arguments
 * @cad: string entered by user
 * @length: number of paths
 * @con: command counter
 * @av: name of program
 * Return: void function
 */
void execute(char **com, char **s, char *cad, int length, int con, char *av)
{
	path(com);
	s = travel(s, cad);
	if (stat(s[0], &st) == -1)
	{
		s[0] = status(s[0], com, length);
		if (!s[0])
		{
			_printf("%s: %i: %s: not found\n", av, con, cad);
			_free(cad, s, com);
			kill(getpid(), SIGTERM);
		}
	}
	execve(s[0], s, NULL);
	_free(cad, s, com);
	kill(getpid(), SIGTERM);
}