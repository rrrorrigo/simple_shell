#ifndef _HOLBERTON_H
#define _HOLBERTON_H
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
/**
 * struct printer - conects format specifier with its corresponding function.
 * @flag: format specifier.
 * @function: pointer to @flag especific function.
 */

typedef struct printer
{
	char flag;
	int (*function)(va_list);
} printer_t;
struct stat st;
void enviroment(void);
int _putchar(char c);
int _printf(const char *format, ...);
int print_c(va_list arg);
int print_s(va_list arg);
int print_i(va_list arg);
extern char **environ;
char *entrada(char *cad, size_t largo);
char **travel(char **s, char *cad);
int _strlen(const char *s);
char *_getenv(const char *name);
int longer(char *a);
char *status(char *p, char **s, int length);
int lengthPath(void);
char **path(char **p);
void _free(char *cad, char **s, char **com);
void execute(char **com, char **s, char *cad, int length, int con, char *av);
#endif
