#include "./Includes/ft_printf.h"

void	ft_print_nbr(t_info *info, char *str, va_list ap)
{
	int i;
	char tmp;
	char len;

	i = 0;
	tmp = va_arg(ap);	
	len = ft_strlen(str);
	if (info->minus == '-')
	{
		while (*str && *str != '*')
			info->count += ft_putchar(str); 
			while (len++ < info->field_width)
				info->count += ft_putchar(' ');
	} 
	else
	{
		while (len++ < info->field_width)
		{
		}
	}	
}
