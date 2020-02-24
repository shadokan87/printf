

#include "lprintf.h"

void	reset_struct(curr *flag)
{
	flag->arg = NULL;
	flag->type = '0';
	flag->precision = 0;
	flag->width = 0;
	flag->width_type = 0;
}