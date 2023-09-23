#include "main.h"

/**
 * _puts - print a string with new line
 * @str: the string to print
 *
 * Return: void
 */

int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * _putchar - writes the character c to stdout
 * @c: the character to print
 *
 * Return: 1 or -1
 */

int _putchar(int c)
{
	static int n;
	static char buf[BUF_SIZE];

	if (c ==BUF_FLUSH || n >= BUF_SIZE)
	{
		write(1, buf, n)
			n = 0;
	}
	if (c != BUF_FLUSH)
		buf[n++] = c;
	return (1);
}
