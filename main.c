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
	int bucle = 1, id, b, l = lengthPath(), con = 0;
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
				lines(cad);
			com = malloc(sizeof(char *) * (l + 1));
			if (!com)
				lines2(cad, s, com);
			id = fork();
			if (id == 0)
			{
				return (execute(com, s, cad, l, con, av[0]));
			}
			else
			{
				waitpid(-1, &b, 0);
				_free(cad, s, com);
				if (!isatty(0))
				{
					if (WIFEXITED(b))
						return (WEXITSTATUS(b));
					else
						return (0);
				}
			}
		}
		else
			free(cad);
	}
	return (0);
}
