#include "main.h"

void print_binary(unsigned long int l)
{
	int g, flag;

	if (l == 0)
		_putchar('0');
	for (flag = 0, g = sizeof(l) * 8 - 1; g >= 0; g--)
	{
		if ((l >> g) & 1)
			flag = 1;
		if (flag == 1)
			((l >> g) & 1) ? _putchar('1') : _putchar('0');
	}
}
