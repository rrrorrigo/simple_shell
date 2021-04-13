#include "holberton.h"
/**
 * main - function that create a simple shell and
 * and accept a rout as input with arguments
 * @ac: counter of arguments (unused)
 * @av: the arguments passed to the program, we used it to print the name
 * of the program.
 * Return: Nothing if success, -1 if an error occurred
 */

int main(__attribute__((unused)) int ac, char *av[])
{
	int bucle = 1, id, b, length = lengthPath(), con = 0;
	size_t largo = 0;
	char **s, **com, *cad = NULL;

	while (bucle)
	{
		cad = entrada(cad, largo);
		if (cad)
		{
			con++;
			s = malloc(sizeof(char *) * (longer(cad) + 1));
			if (!s)
			{
				free(cad);
				free(s);
				exit(-1);
			}
			com = malloc(sizeof(char *) * (length + 1));
			if (!com)
			{
				_free(cad, s, com);
				exit(-1);
			}
			id = fork();
			if (id == 0)
			{
				execute(com, s, cad, length, con, av[0]);
			}
			else
			{
				wait(&b);
				_free(cad, s, com);
			}
		}
		else
			free(cad);
	}
	return (-1);
}
