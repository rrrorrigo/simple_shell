#ifndef _HOLBERTON_H
#define _HOLBERTON_H
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

void lines2(char *cad, char **s, char **com);
void lines(char *cad);
void enviroment(void);
int _putchar(char c);
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
int execute(char **com, char **s, char *cad, int length, int con, char *av);
char *_strdup(char *str);
int print(char *str);
int printnumber(int n);
#endif
