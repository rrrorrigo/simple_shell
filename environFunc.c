#include "holberton.h"
/**
 * _strlen - string length
 * @string: string to know the length
 * Return: number of chars
 */

int _strlen(const char *string)
{
	int i = 0;

	while (string[i])
		i++;
	return (i);
}

/**
 * _getenv - gets the enviroment
 * @name: name of the enviroment
 * Return: enviroment
 */
char *_getenv(const char *name)
{
	int i = 0, j, ii = 0;

	j = _strlen(name);

	while (environ[i])
	{
		while (environ[i][ii] == name[ii] && ii < j)
		{
			if (environ[i][ii + 1] == '=')
				return (environ[i]);
			ii++;
		}
		i++;
	}
	return (NULL);
}

/**
 * longer - Longer of a string without conditions
 * @a: string
 * Return: number of chars without conditions
 */
int longer(char *a)
{
	int check = 1, i = 0;

	for (; a[i]; i++)
	{
		if (a[i] == ' ' && a[i + 1] != ' ')
			check++;
		else if (a[i] == ' ' && a[i + 1] != '\n' && a[i + 1] != '\t')
			check++;
	}
	return (check);
}
/**
 * enviroment - gets the enviroment
 * Return: void function
 */
void enviroment(void)
{
	int a = 0;

	while (environ[a] != NULL)
	{
		print(environ[a]);
		a++;
	}
}
