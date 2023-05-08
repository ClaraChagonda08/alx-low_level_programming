#include "main.h"
/**
 * Author Clara
 *
 */
ssize_t read_textfile(const char *fname, size_t letrs)
{
	int d;
	int i, z;
	char *buf;
	if (!fname)
		return (0);
	d = open(fname, O_RDONLY);
	if (d < 0)
		return (0);
	buf = malloc(sizeof(char) * letrs);
	if (!buf)
		return (0);
	i = read(d, buf, letrs);
	if (i < 0)
	{
		free(buf);
		return (0);
	}
	buf[x] = '\0';
	close(d);
	z = write(STDOUT_FILENO, buf, x);
	if (z < 0)
	{
		free(buf);
		return (0);
	}
	free(buf);
	return (z);
}

