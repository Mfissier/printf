#include "Includes/ft_printf.h"

void	ft_print_string_for_conv(char *str, va_list ap, t_info *info)
{
	char *tmp;
	info->char_z = 0;
	if (*str == 'c')
	{
		tmp = malloc(sizeof(char) * 1);
		if (!tmp)
			return;
		tmp[0] = va_arg(ap, int);
		if (tmp[0] == 0)
			info->char_z = 1;
		ft_print_string(info, tmp);
		free(tmp);
	}
	if (*str == 's')
	{
		tmp = va_arg(ap, char *);
		if (!tmp)
			tmp = "(null)";
		ft_print_string(info, tmp);
	}
}
