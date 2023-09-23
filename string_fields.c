#include "main.h"

/**
 * get_precision _ gits the precision form the format string
 * @p: the format string
 * @flags: the parameters struct
 * @list: the argument pointer
 *
 * Return: new pointer
 */

char *get_precision(char *p, flags_t flags, va_list list)
{
	int i = 0;

	if (*p != '.')
		return (p);
	p++;
	if (*p == '*')
	{
		i = va_arg(ap, int);
		p++;
	}
	else
	{
		while (_isdigit(*p))
			i = i * 10 + (*p++ - '0');
	}
	flags->precision = i;
	return (p);
}
