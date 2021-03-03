#include "./Includes/ft_printf.h"

void	ft_print_nbr(t_info *info, char *str, va_list ap)
{
	int i;
	char tmp;
	int len;

	i = -1;
	tmp = va_arg(ap, int);	
	len = 0;
	while(str[++i])
	{
		if (str[i] != '*')
			len++;
	}
	i = 0;
	if (info->flag->minus == '-')
	{
		if (info->sign == 1)
			info->count += ft_putchar('-');
		if (info->iszero == 1)
			info->count += ft_putchar('0');
		while (*str)
		{
			if (*str != '*')
				info->count += ft_putchar(*str); 
			str++;
		}
		while (len++ < info->field_width)
			info->count += ft_putchar(' ');
	} 
	else
	{
		while (len++ < info->field_width)
				info->count += ft_putchar(' ');
		if (info->isp == 1)
		{
			info->count += ft_putchar('0');
			info->count += ft_putchar('x');
		}
		if (info->sign == 1)
			info->count += ft_putchar('-');
		if (info->iszero == 1)
			info->count += ft_putchar('0');
		while (*str)
		{
			if (*str != '*')
				info->count += ft_putchar(*str); 
			str++;
		}
	}	
}
