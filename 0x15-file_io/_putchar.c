#include <unistd.h>
/**
 * Author Clara
 *
 */
int _putchar(char a)
{
	return (write(1, &a, 1));
}
