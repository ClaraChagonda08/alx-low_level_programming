#include <stdlib.h>
#include <stdio.h>
#include "3-calc.h"

int (*get_op_func(char *s))(int, int);

/**
 * main - will print result of a caluclation based on arguments
 *
 * @argc: argument count
 * @argv: arguments
 * Return: prints result of calculation or error, 0 if success exit if not
 */
int main(int argc, char *argv[])
{
	int a, b;
	char c;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);
	c = *argv[2];

	if (argv[2][1] != '\0' || *get_op_func(argv[2]) == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	if ((c == '/' || c == '%') && b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	printf("%d\n", (*get_op_func(argv[2]))(a, b));

	return (0);
}
