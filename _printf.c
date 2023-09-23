#include "main.h"

/**
 * _printf - prints anything
 * @format: the format string
 *
 * Return: number of bytes printed
 */

int _printf(const char *format, ...)
{
	int n = 0;
	va_list list;
	char *p, *start;
	flags_t flags = FLAGS_INT;

	va_start(list, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		int_flags(&flags, list);
		if (*p != '%')
		{
			n += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &flags))
		{
			p++;
		}
		p = grt_width(p, &flags, list);
		p = get_precision(p, &flags, list);
		if (get_modifier(p, &flags))
			p++;
		if (!get_specifier(p))
			n += print_form_to(start, p, flags.l_modifier
				|| flags.h_modifier ? p - 1 : 0);
		else
			n += get_print_function(p, list, &flags);
	}
	_putchar(BUF_FLUSH);
	va_end(list);
	return (n);
}
