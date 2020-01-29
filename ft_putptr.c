
#include "lprintf.h"

void	ft_putptr(unsigned long int ptr)
{
	ft_putstr("0x");
	ft_putstr(ft_putnbr_base(ptr, HEXD));
}
