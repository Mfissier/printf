#include "./Includes/ft_printf.h"
char			*ft_get_field_width(t_info *info, char *str, va_list ap)
{
	info->field_width = -1;
	if (*str >= '1' && *str <= '9')
		info->field_width = ft_atoi(str);
	while (*str >= '0' && *str <= '9')
		str++;
	if (*str == '*')
	{
		info->field_width = va_arg(ap, int);
		if (info->field_width < 0)
		{
			info->field_width = info->field_width;
			info->flag->minus = '-';
		}
		str++;
	}
	if (*str >= '1' && *str <= '9')
		info->field_width = ft_atoi(str);
	while (*str >= '0' && *str <= '9')
		str++;
	return (str);
}
