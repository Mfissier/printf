#include "./Includes/ft_printf.h"

int ft_printf(const char *contain, ...)
{
	va_list ap;
	char *str;

	t_info info;
	if(!(info.flag = (t_flag_info*)malloc(sizeof(t_flag_info) * 1)))
		return (-1);
	info.count = 0;
	if (!contain)
		return(-1);
	va_start(ap, contain);
	str = (char *)contain;
	while(*str)
	{
		while (((*str && *str != '%')) || (*(str + 1) == '%' && *str == '%'))
		{
			while (*str && *str != '%')
				info.count += ft_putchar(*(str++));	
			while (*(str + 1) && *(str + 1) == '%' && *str == '%')
			{
				info.count += ft_putchar(*str);	
				str += 2;
			}
		}	
		if (*str == '%')
			str++;
		if (*str)
			str = ft_print_result(str, ap, &info);
		if (!*str++)
			break;
	}
	free(info.flag);
	va_end(ap);
	return (info.count);
}
