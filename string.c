#include "holberton.h"
/**
 * print - function that print
 * @str: string to print
 * Return: Always 1
 */
int print(char *str)
{
	int i = 0;

	for (; str[i]; i++)
		_putchar(str[i]);
	return (1);
}
/**
 * printnumber - function that print number
 * @n: number to print
 * Return: Always 1
 */
int printnumber(int n)
{
	int divisor = 1;

	while (n / divisor > 9)
		divisor = divisor * 10;
	while (divisor != 0)
	{
		_putchar('0' + n / divisor);
		n = n % divisor;
		divisor = divisor / 10;
	}
	return (1);
}
