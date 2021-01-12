#include "../Includes/ft_printf.h"

int ft_printf(const char *str, ...)
{
	va_list ap;
	t_env	arg;

	arg.cur = 3;

	if (!str)
		return(-1);
	va_start(ap, str);
	va_arg(ap, int);
	printf("%d", va_arg(ap, int));	
	printf("%s\n", str);
	va_end(ap);
	return(0);
}
