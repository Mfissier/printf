#include "Includes/ft_printf.h"

void	ft_print_string_for_conv(char *str, va_list ap, t_info *info)
{
	char *tmp;
	if (*str == 'c')
		info->count += ft_putchar(va_arg(ap, int));
	if (*str == 's')
	{
		tmp = va_arg(ap, char *);
		while(*tmp)
			info->count += ft_putchar(*(tmp++));
	}
}
