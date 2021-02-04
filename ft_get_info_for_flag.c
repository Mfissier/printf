#include "./Includes/ft_printf.h"

char		*ft_get_info_for_flag(t_flag_info *flag, char *str)
{
	while (*str == '#' || *str == '-' || *str == '+' \
		|| *str == ' ' || *str == '0')
	{
		if (*str == '#')
			flag->hash = '#';
		else if (*str == '-')
			flag->minus = '-';
		else if (*str == '+')
			flag->plus = '+';
		else if (*str == ' ')
			flag->space = ' ';
		else if (*str == '0')
			flag->zero = 'y';
		else
			(ft_putstr("something wrong with flags"));
		str++;
	}
	return (str);
}
