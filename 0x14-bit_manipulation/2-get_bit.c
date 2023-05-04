#include "main.h"

int get_bit(unsigned long int l, unsigned int index)
{
	return ((index > (8 * sizeof(l) - 1)) ? -1 : (int)(l >> index) & 1);
}
