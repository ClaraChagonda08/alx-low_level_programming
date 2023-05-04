#include "main.h"

unsigned int _stoi(char c)
{
	return ((unsigned int) c - '0');
}

/**
 * _strlen - calculates string lanth
 * @d is the input
 * Return string length
 */

unsigned int _strlen(const char *d)
{
	unsigned int i;

	for (i = 0; d[i]; i++)
		;
	return (i);
}

/**
 * author: Clara
 * @a string to convert
 * Return unsigned decimal number
 */

unsigned int binary_to_uint(const char *a)
{
	int i;
	unsigned int result, tmp, expo;

	if (!a)
		return (0);
	result = tmp = 0;
	expo = 1;
	for (i = _strlen(a) - 1; a[i]; i--, expo *= 2)
	{
		if (a[i] != '0' && a[i] != '1')
			return (0);
		tmp = _stoi(a[i]);
		result += tmp * expo;
	}
	return (result);
}

