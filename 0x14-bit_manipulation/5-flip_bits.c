#include "main.h"

unsigned int flip_bits(unsigned long int l, unsigned long int o)
{
	int g, cla;

	cla = 0;
	for (g = 8 * sizeof(l) - 1; g >= 0; g--)
		if (((l ^ o) >> g) & 1)
			cla++;
	return (cla);
}

