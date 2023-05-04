#include <unistd.h>
int _putchar(char d)
{
	return (write(1, &d, 1));
}
