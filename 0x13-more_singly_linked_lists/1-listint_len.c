#include "lists.h"
/**
 * returns the number of elements in a linked listint_t list
 */
size_t listint_len(const listint_t *h)
{
	size_t i;

	for (i = 0; h; i++)
		h = h->next;
	return (i);
}
