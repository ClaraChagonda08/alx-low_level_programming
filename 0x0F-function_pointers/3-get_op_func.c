#include <stdlib.h>
#include <stdio.h>
#include "3-calc.h"

/**
 * get_op_func - determines the correct function to use for operator
 *
 * @s: operator to match to a function
 * Return: pointer to correct function to calculate or NULL if no match
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	i = 0;

	while (ops[i].op)
	{
		if (ops[i].op[0] == *s)
			return (ops[i].f);
		i++;
	}

	return (ops[i].f);
}
