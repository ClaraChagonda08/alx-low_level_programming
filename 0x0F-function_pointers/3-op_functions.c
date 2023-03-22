#include <stdlib.h>
#include <stdio.h>
#include "3-calc.h"

/**
 * op_add - returns sum of a and b
 *
 * @a: first in
 * @b: second int
 * Return: result of operation
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - returns difference between a and b
 *
 * @a: first in
 * @b: second int
 * Return: result of operation
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - returns product of a and b
 *
 * @a: first in
 * @b: second int
 * Return: result of operation
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - returns quotient of a by b
 *
 * @a: first in
 * @b: second int
 * Return: result of operation
 */
int op_div(int a, int b)
{
	if (b == 0)
		return (0);
	return (a / b);
}

/**
 * op_mod - returns modulus of a by b
 *
 * @a: first in
 * @b: second int
 * Return: result of operation
 */
int op_mod(int a, int b)
{
	if (b == 0)
		return (0);
	return (a % b);
}
