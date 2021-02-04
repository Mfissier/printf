
#include "./Includes/ft_printf.h"

void		ft_print_nbr_for_conv(char *str, va_list ap)
{
	int nbr;
//	str = ft_get_info_for_flag(t_flag_info, str);
	if (*str == 'd')
		nbr = va_arg(ap, int);
	if (*str == 'i')

	printf("arg ap : %d\n", nbr);
	printf("%s\n", str);
}
