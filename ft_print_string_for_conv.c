#include "Includes/ft_printf.h"

void	ft_print_string_for_conv(char *str, va_list ap, t_info *info)
{
	if (*str == 'c')
		ft_putchar(va_arg(ap, int));
	info->count++;
}
