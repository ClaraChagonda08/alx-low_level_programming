#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_string - print strings
 *
 * @list: list of arguments
 * Return: void
 */
void print_string(va_list list)
{
	char *temp;

	temp = va_arg(list, char *);
	if (temp == NULL)
	{
		printf("(nil)");
		return;
	}
	printf("%s", temp);
}

/**
 * print_char - print a char
 *
 * @list: list of arguments
 * Return: void
 */
void print_char(va_list list)
{
	printf("%c", va_arg(list, int));
}

/**
 * print_int - prints an int
 *
 * @list: list of arguments
 * Return: void
 */
void print_int(va_list list)
{
	printf("%d", va_arg(list, int));
}

/**
 * print_float - prints a float
 *
 * @list: list of arguments
 * Return: void
 */
void print_float(va_list list)
{
	printf("%f", va_arg(list, double));
}

/**
 * print_all - prints anything based on passed format string
 *
 * @format: constant that tells what type of format to print
 * Return: void
 */
void print_all(const char * const format, ...)
{
	va_list list;
	type_print typs[] = {
		{'c', print_char},
		{'i', print_int},
		{'f', print_float},
		{'s', print_string},
		{'\0', NULL}
	};
	int i, k;
	char *separator;

	va_start(list, format);
	i = 0;
	k = 0;
	separator = "";
	while (format != NULL && *(format + k) != '\0')
	{
		while (typs[i].type_name && typs[i].t != *(format + k))
		{
			i++;
		}
		if (typs[i].type_name != NULL)
		{
			printf("%s", separator);
			typs[i].type_name(list);
			separator = ", ";
		}
		k++;
		i = 0;
	}
	printf("\n");
	va_end(list);
}

