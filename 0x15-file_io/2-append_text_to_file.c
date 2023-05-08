#include "main.h"

/**
 * Author Clara
 *
 */
int append_text_to_file(const char *fname, char *content)
{
	int d, a, b = 0;

	if (!fname)
		return (-1);

	d = open(fname, O_WRONLY | O_APPEND);
	if (d < 0)
		return (-1);

	if (content)
	{
		while (content[b])
			b++;
		a = write(d, content, b);
		if (a != b)
			return (-1);
	}

	close(d);

	return (1);
}

