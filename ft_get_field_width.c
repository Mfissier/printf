#include "./Includes/ft_printf.h"
void	ft_take_point(t_info *info, char *str)
{
	int i;

	i = 0;
	info->pt_n = 0;
	info->n_pt_n = 0;
	info->n_pt = 0;
	if (str[i] == '.')
		info->pt_n = 1 + 0 * i++;
	while((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
	{
		if (info->pt_n == 0 && str[i] == '.')
		{
			info->n_pt = 1;
			if (str[++i] >= '0' && str[i] <= '9')
			{
				info->n_pt_n = 1;
				info->n_pt = 0;
			}
		}
		i++;
	}
}
char			*ft_get_field_width(t_info *info, char *str, va_list ap)
{
	ft_take_point(info, str);
	info->field_width = -1;
	if (*str >= '1' && *str <= '9')
		info->field_width = ft_atoi(str);
	while ((*str >= '0' && *str <= '9'))
		str++;
	if (*str == '.')
		str++;
	if (*str == '*')
	{
		info->field_width = va_arg(ap, int);
		if (info->field_width < 0)
		{
			info->field_width = -info->field_width; 
			info->flag->minus = '-';
		}
		str++;
	}
	if (*str >= '1' && *str <= '9')
		info->field_width_next = ft_atoi(str);
	while (*str >= '0' && *str <= '9')
		str++;
	return (str);
}
