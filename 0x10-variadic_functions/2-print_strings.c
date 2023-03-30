#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * print_strings - prints a string followed by a new line
 *
 * @separator: string to print between strings
 * @n: count of strings to print
 * Return: void
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list strings;
	char *temp;
	unsigned int i;

	va_start(strings, n);
	for (i = 0; i < n; i++)
	{
		temp = va_arg(strings, char *);
		if (temp == NULL)
			temp = "(nil)";
		printf("%s", temp);
		if (separator != NULL && i != n - 1)
			printf("%s", separator);
	}
	putchar('\n');
	va_end(strings);
}
