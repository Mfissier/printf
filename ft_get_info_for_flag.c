#include "./Includes/ft_printf.h"

char		*ft_get_info_for_flag(t_info *info, char *str)
{
	ft_bzero(info->flag, sizeof(t_flag_info));
	while (*str == '#' || *str == '-' || *str == '+' \
		|| *str == ' ' || *str == '0')
	{
		if (*str == '#')
			info->flag->hash = '#';
		else if (*str == '-')
			info->flag->minus = '-';
		else if (*str == '+')
			info->flag->plus = '+';
		else if (*str == ' ')
			info->flag->space = ' ';
		else if (*str == '0')
			info->flag->zero = 'y';
		else
			(ft_putstr("something wrong with flags"));
		str++;
	}
	return (str);
}
