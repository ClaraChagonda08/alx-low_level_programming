#include "main.h"

int set_bit(unsigned long int *l, unsigned int index)
{
	if (index > (8 * sizeof(*l)) - 1)
		return (-1);
	*l = *l | (1 << index);
	return (1);
