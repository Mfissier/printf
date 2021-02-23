#include "./Includes/ft_printf.h"

char		*ft_print_result(char *str, va_list ap, t_info *info)
{
	str = ft_get_info_for_flag(info, str);
	str = ft_get_field_width(info, str, ap);
	if (ft_str_all_chr(str, "diouxXDOUpb"))
		ft_print_nbr_for_conv(str, ap, info);
	else if (ft_str_all_chr(str, "cCsS"))
		ft_print_string_for_conv(str, ap, info);
	return(str);
}















/*
	while (*str == '#' || *str == '-' || *str == '+' || *str == ' ' || *str == '0')
	{
		if(*str == '#')
			printf("hash\n");
		else if(*str == '-')
			printf("mettre en minuscul\n");	
		else if(*str == '+')
			printf("mettre en majuscul\n");	
		else if(*str == ' ')
			printf("mettre des espaces\n");	
		else if(*str == '0')
			printf("mettre des zero\n");	
		str++;
	}
*/
