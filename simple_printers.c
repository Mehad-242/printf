#include "main.h"
/**
 * print_from_to -prints a range of char addresses
 * @start: starting address
 * @stop: stoping address
 * @except: except address
 *
 * Return: number bytes printed
 */

int print_form_to(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != exept)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}

/**
 * print_rev - prints string in reverse
 * @p: string
 * @flags: the parameters stutic
 *
 * Return: number bytes printed
 */

int print_rev(va_list list, flags_t *flags)
{
	int lenth, i = 0;
	char *str = va_arg(list, char *);
	(void)flags;

	if (str)
	{
		for (lenth = 0; *str; str++)
			lenth++;
		for(; lenth > 0; lenth--,str--)
			 i += _putchar(*str);
	}
	return (i);
}
/**
 *
 *
 * Return: number bttes printed
 */
int print_rot13(va_list list, flags_t *flags)
{
	int i, index;
	int count = 0;
	char array[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM     nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(list, char *);
	(void)flags;

	i = 0;
	index = 0;
	while (a[i])
	{
		if ((a[i] >= 'A' && a[i] = 'Z')
			|| (a[i] >= 'a' && a[i] <= 'z'))
		{
			index = a[i] - 65;
			count += _putchar(array[index]);
		}
		else
			count += _putchar(a[i]);
		i++;
	}
	return (count);
}
