#include <stdio.h>
#include "lists.h"
/**
 * prints all elements of a list_t list
 */
size_t print_listint(const listint_t *h)
{
	size_t i;

	for (i = 0; h; i++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	return (i);
}
