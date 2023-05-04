#include "main.h"
#include <stdio.h>


int get_endianness(void)
{
	int g;
	char *test;

	g = 1;
	test = (char *)&g;
	return ((int)test[0]);
}
