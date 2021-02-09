#include "./Includes/ft_printf.h"

void		print_result(unsigned long long nbr, t_info *info, int base)
{
	int		i;
	char		str[50];
	int		len;
	const char	tab[] = "0123456789abcdef";

	i = 49;
	info->sign = 0;
	info->iszero = 0;
	/*if (nbr == 0)
	  info->iszero = 1;
	  info->sign = print_sign(info, info->sign);*/
	str[49] = '\0';
	while (nbr >= 1)
	{
		str[--i] = (tab[nbr % base]);
		nbr /= base;
	}
	len = 49 - i;
	if (info->iszero == 1)
		len = 1;
	while (i >= 0)
		str[--i] = '*';
	//print_nbr(info, str, len);
}

void		print_result_d(long long nbr, t_info *info, int base)
{
	int					i;
	char				str[50];
	int					len;
	const char			tab[] = "0123456789abcdef";

	i = 49;
	info->sign = 0;
	info->iszero = 0;
	if (nbr < 0)
		info->sign = 1;
	if (nbr == 0)
		info->iszero = 1;
	//	info->sign = print_sign(info, info->sign);
	str[49] = '\0';
	while (nbr)
	{
		str[--i] = (tab[ft_abs(nbr % base)]);
		nbr /= base;
	}
	len = 49 - i;
	if (info->iszero == 1)
		len = 1;
	while (i >= 0)
		str[--i] = '*';
	//print_nbr(info, str, len);
}

void		print_result_capx(unsigned long long nbr, \
		t_info *info, int base)
{
	int					i;
	char				str[50];
	int					len;
	const char			tab[] = "0123456789ABCDEF";

	i = 49;
	info->sign = 0;
	info->iszero = 0;
	if (nbr == 0)
		info->iszero = 1;
	//	info->sign = print_sign(info, info->sign);
	str[49] = '\0';
	while (nbr >= 1)
	{
		str[--i] = (tab[nbr % base]);
		nbr /= base;
	}
	len = 49 - i;
	if (info->iszero == 1)
		len = 1;
	while (i >= 0)
		str[--i] = '*';
	//print_nbr(info, str, len);
}

void		get_take_for_convert(char s, t_info *info)
{
	info->isp = 0;
	if (s == 'i' || s == 'd')
		info->conversion_specifier = 'd';
	if (s == 'p')
	{
		info->isp = 1;
		info->flag->hash = '#';
		ft_strcpy(info->len_mod, "l");
		info->conversion_specifier = 'x';
	}
	if (s == 'D')
	{
		ft_strcpy(info->len_mod, "l");
		info->conversion_specifier = 'd';
	}
	if (s == 'O')
	{
		ft_strcpy(info->len_mod, "l");
		info->conversion_specifier = 'o';
	}
	if (s == 'U')
	{
		ft_strcpy(info->len_mod, "l");
		info->conversion_specifier = 'u';
	}
}

void		ft_print_nbr_for_conv(char *str, va_list ap, t_info *info)
{
	unsigned long long	nbr1 = 0;
	long long			nbr2 = 0;

	char *test;
	nbr1 = 3;
	nbr2 = 3;
	
	test = va_arg(ap, char*);
	get_take_for_convert(*str, info);
	//if (info->conversion_specifier == 'd')
	//	printf("printf d");

	/*nbr2 = number_to_print_signed(info, ap);
	  else
	  nbr1 = number_to_print_unsigned(info, ap);*/

	if (info->conversion_specifier == 'd')
		printf("print int\n");
	else if (info->conversion_specifier == 'u')
		printf("print unsigned\n");
	else if (info->conversion_specifier == 'o')
		printf("print o\n");
	else if (info->conversion_specifier == 'x')
		printf("print hexa\n");
	else if (info->conversion_specifier == 'X')
		printf("print HEXA\n");
	//print_result_d(nbr2, info, 10);
	//print_result(nbr1, info, 10);
	//print_result(nbr1, info, 8);
	//print_result(nbr1, info, 16);
	//print_result_capx(nbr1, info, 16);
}
