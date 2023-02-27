#include <stdio.h>
#include "main.h"

/**
 * _atoi - return a num inside of a string
 *
 * @s: pointer for string to parse
 * Return: int pulled from string, 0 if none
 */
int _atoi(char *s)
{
	unsigned int num = 0;
	int flag = -1, i = 0, neg = 1;

	if (*s == '\0')
		flag = 1;
	for (i = 0; flag == -1; i++)
	{
		if ((*(s + i) >= '0') && (*(s + i) <= '9'))
		{
			if (num != 0)
				num = ((num * 10) + (*(s + i) - '0'));
			else
				num = (*(s + i) - '0');
		}
		if (*(s + i + 1) == '\0')
			flag = 1;
		if (*(s + i) == '-')
			neg *= -1;
		if (num != 0)
		{
			if ((*(s + i + 1) < '0') || (*(s + i + 1) > '9'))
				flag = 0;
		}
	}
	return (neg * num);
}
