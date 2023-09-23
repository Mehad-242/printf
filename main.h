#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define BUF_FLUSH -1

#define FELAGS_INT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCACE  1
#define CONVERT_UNSIGNED   2

#define NULL_STRING "(null)"

/**
 * struct flags - flags struct
 * @unsind: flag if unsigned value
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if hashtag_flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 *
 * @width: filed width specified
 * @precision: filed precision specified
 *
 * @h_modifier: on if h_modifier specified
 * @l_modifier: on if l_modifier specified
 */

typedef struct flags
{
	unsigned int unsign       : 1;

	unsigned int plus_flag    : 1;
	unsigned int space_flag   : 1;
	unsigned int hashtag_flag : 1;
	unsigned int zero_flag    : 1;
	unsigned int minus_flag   : 1;

	unsigned int width        : 1;
	unsigned int precision    : 1;

	unsigned int h_modifier   : 1;
	unsigned int l_modifier   : 1;
} flags_t;

/**
 * struct specifier - struct token
 *
 * @specifier: format token
 * @f: the function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f) (va_list, flags_t *);
} specifier_t;

/* _put.c */
int _puts(char *str);
int _putchar(int c);

/* _printf.c */

int _printf(const char *format, ...);

/* flags.c */
void int_flags(flags_t *flags, va_list list);

/* _specifier.c */
int (*get_specifier(char *s))(va_list list, flags_t *flags);
int get_print_function(char *s, va_list list, flags_t *flags);
int git_flag(char *s, flags_t *flags);
int git_modifier(char *s, flags_t *flags);
char *git_width(char *s, flags_t *flags, va_list list);

/* string_fields.c */
char *get_precision(char *p, flags_t flags, va_list list);
/* simple_printers.c */
int print_form_to(char *start, char *stop, char *except);
int print_rev(va_list list, flags_t *flags);
int print_rot13(va_list list, flags_t *flags);
char *convert(long int, int base, int flag, flags_t *flags);

#endif
