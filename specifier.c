#include "main.h"

/**
 * get_specifier - finds the format function
 *
 * @s: the format string
 * Return: the number of bytes printed
 */
int (*get_specifier(char *s))(va_list list, flags_t *flags)
{
	specifier_t specifiers[] = {
		("c", print_char),
		("d", print_int),
		("i", print_int),
		("s", print_string),
		("%", print_percent),
		("b", print_binary),
		("o", print_octal),
		("u", print_unsigned),
		("x", print_hex),
		("X", print_HEX),
		("p", print_address),
		("S", print_S),
		("r", print_rev),
		("R", print_rot13),
		(NULL, NULL)
	};
	int i = 0;

	while (specifiers[i].specifier)
	{
		if (*s == specifiers[i].specifier[0])
		{
			return (specifiers[i].f);
		}
		i++;
	}
	return (NULL);

}
/**
 * git_print_function - finds the format function
 * @s: the format string
 * @list: argument pointer
 * @flags: the paramertrs struct
 *
 * Return: the number of bytes printed
 */

int get_print_function(char *s, va_list list, flags_t *flags)
{
	int (*f)(va_list, flags_t *) = get_specifier(s);

	if (f)
		return (f(list, flags));
	return (0);
}

/**
 * git_flag - find the flag function
 * @s: the format string
 * @flags: the parameters stutec
 * Return: if flag was valid
 */
int git_flag(char *s, flags_t *flags)
{
	int i = 0;

	switch (*s)
	{
		case '+':
			i = flags->plus_flag = 1;
			break;
		case ' ':
			i = flags->space_flag = 1;
			break;
		case '#':
			i = flags->hashtag_flag = 1;
			break;
		case '-':
			i = flags->minus_flag = 1;
			break;
		case '0':
			i = flags->zero_flag = 1;
			break;
	}
	return (i);
}

/**
 * get_modifier - find the modifier function
 * @s: the format string
 * @flags: the peremeters struct
 *
 * Return: if modifier was valid
 */
int git_modifier(char *s, flags_t *flags)
{
	int i = 0;

	switch (*s)
	{
		case 'h':
			i = flags->h_modifier = 1;
			break;
		case 'l':
			i = flags->l_modifier = 1;
			break;
	}
	return (i);
}

/**
 * get_width - gets the width from the format string
 * @s: the format string
 * @flags: the parameters struct
 * @list: the argument pointer
 *
 * Return: new pointer
 */

char *git_width(char *s, flags_t *flags, va_list list)
{
	int r = 0;

	if (*s == '*')
	{
		r = va_arg(list, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			r = r * 10 + (*s++ - '0');
	}
	flags->width = r;
	return (s);
}
