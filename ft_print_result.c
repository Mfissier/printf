#include "./Includes/ft_printf.h"

char		*ft_print_result(char *str, va_list ap, t_info *info)
{
	ft_putstr_fd(str, 1);
	va_arg(ap, int);
	info->count += 1;
	return(str);
}
