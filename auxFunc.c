#include "holberton.h"
/**
 * _strdup - prints buffer in hexa
 * @str: the size of the memory to print
 * Return: Nothing.
 */

char *_strdup(char *str)
{
	int a = 0;
	int b = 0;
	char *new;

	if (str == NULL)
		return (NULL);
	while (str[a] != '\0')
		a++;
	a++;
	new = malloc(sizeof(char) * a);
	if (new == NULL)
		return (NULL);
	for (; b < a; b++)
		new[b] = str[b];
	return (new);
}
/**
 * _strcmp - a.
 *
 * @s1: external value
 * @s2: external value
 *
 *Return: dest.
 */
int _strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (-1);
	while ((*s1 != '\0' && *s2 != '\0') && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 != *s2)
		return (*s1 - *s2);
	else
		return (0);
}
/**
 * entrada - function that print prompt and asks for line
 * @cadena: pointer to return with the line obtained
 * @largo: string length
 * Return: cadena if success, if an error occurred exit the program.
 */
char *entrada(char *cadena, size_t largo)
{
	int check;
	char *e = "exit", *e2 = NULL, *e3 = "\n", *env = "env", *aux, *aux2;

	if (isatty(0))
	{
		_putchar('$');
		_putchar(' ');
	}
	check = getline(&cadena, &largo, stdin);
	if (check == -1)
	{
		free(cadena);
		if (isatty(0))
			_putchar('\n');
		exit(-1);
	}
	if (_strcmp(cadena, e3) == 0)
	{
		free(cadena);
		return (e2);
	}
	cadena = strtok(cadena, e3);
	aux = _strdup(cadena);
	aux2 = strtok(aux, " \t");
	if (_strcmp(aux2, e) == 0)
	{
		free(cadena);
		free(aux);
		exit(0);
	}
	free(aux);
	if (_strcmp(cadena, env) == 0)
	{
		enviroment();
		free(cadena);
		return (e2);
	}
	return (cadena);
}
/**
 * travel - function that travel cadena and set the value of this on string
 * @string: string of characters
 * @cadena: string to copy into string variable
 * Return: string with the value.
 */
char **travel(char **string, char *cadena)
{
	char *aux;
	int con = 0;

	aux = strtok(cadena, "\n");
	string[con] = strtok(aux, " \t");
	if (!string[con])
	{
		string[con] = NULL;
		return (string);
	}
	while (string[con])
	{
		con++;
		string[con] = strtok(NULL, " \t");
	}
	return (string);
}
/**
 * path - function separate the path into double pointer p
 * @p: pointer to set as value the different path
 * Return: Always p.
 */
char **path(char **p)
{
	char *aux;
	int con = 0;

	aux = strtok(_getenv("PATH"), "=");
	aux = strtok(NULL, "\n");
	p[con] = strtok(aux, ":");
	while (p[con])
	{
		con++;
		p[con] = strtok(NULL, ":");
	}
	return (p);
}
