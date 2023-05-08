#include "main.h"

/**
 * Author Clara
 *
 */
int main(int argc, char *argv[])
{
	int d_r, d_w, x, o, p;
	char buf[BUFSIZ];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	d_r = open(argv[1], O_RDONLY);
	if (d_r < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	d_w = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	while ((x = read(d_r, buf, BUFSIZ)) > 0)
	{
		if (d_w < 0 || write(d_w, buf, x) != x)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(d_r);
			exit(99);
		}
	}
	if (x < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	o = close(d_r);
	p = close(d_w);
	if (o < 0 || p < 0)
	{
		if (o < 0)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", d_r);
		if (p < 0)
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", d_w);
		exit(100);
	}
	return (0);
}

