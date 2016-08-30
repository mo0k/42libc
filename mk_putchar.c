#include <unistd.h>

void	mk_putchar(char c)
{
	write(1, &c, 1);
}
