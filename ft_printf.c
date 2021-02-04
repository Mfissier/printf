#include "./Includes/ft_printf.h"

int ft_printf(const char *contain, ...)
{
	va_list ap;
	char *str;
	t_info info;
	t_flag_info flag;
	info.count = 0;
	if (!contain)
		return(-1);
	va_start(ap, contain);
	str = (char *)contain;
	flag.minus = 'm';
	printf("%c", flag.minus);
	while(*str)
	{
		while(*str && *str != '%')
			info.count += ft_putchar(*(str++));	
		if (*str == '%')
			str++;
		if (*str)
			str = ft_print_result(str, ap, &info, &flag);
		str++;
	}
	va_end(ap);
	return(info.count);
}
