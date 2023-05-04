#include "main.h"

/**
 * author Clara
 * 
 * Returns
 */

int clear_bit(unsigned long int *l, unsigned int index)
{
	*l = *l & ~(1 << index);
	return ((index > 8 * sizeof(*l)) ? -1 : 1);
}

