#include "main.h"

/**
 * Author Clara
 *
 */
int create_file(const char *fname, char *content)
{
	int d, i, z = 0;

	if (!fname)
		return (-1);

	d = open(fname, O_CREAT | O_RDWR | O_TRUNC, 0600);
	if (d < 0)
		return (-1);

	if (content)
	{
		while (content[z])
			z++;
		i = write(d, content, z);
		if (i != z)
			return (-1);
	}

	close(d);

	return (1);
}
