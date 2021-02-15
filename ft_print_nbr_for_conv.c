#include "./Includes/ft_printf.h"

void		print_result(unsigned long long nbr, t_info *info, int base)
{
	int		i;
	char		str[50];
	int		len;
	const char	tab[] = "0123456789abcdef";
	int index;

	index = 0;

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
	while (i >= 0)
		str[--i] = '*';
	while(str[index])
	{
		if (str[index] != '*')
			info->count += ft_putchar(str[index]);
		index++;
	}
	//print_nbr(info, str, len);
}

void		print_result_d(long long nbr, t_info *info, int base, va_list ap)
{
	int		i;
	char		str[50];
	const char	tab[] = "0123456789abcdef";
	int		index;

	index = 0;
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
	while (i >= 0)
		str[--i] = '*';
	while(str[index])
	{
		if (str[index] != '*')
			info->count += ft_putchar(str[index]);
		index++;
	}
	ft_print_nbr(info, str);
	//print_nbr(info, str, len); faire un pont ici pour annalyse des données et ensuite imprimer
}

void		print_result_capx(unsigned long long nbr, \
		t_info *info, int base, va_list ap)
{
	int					i;
	char				str[50];
	int					len;
	const char			tab[] = "0123456789ABCDEF";
	int index;

	index = 0;
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
	while (i >= 0)
		str[--i] = '*';
	while(str[index])
	{
		if (str[index] != '*')
			info->count += ft_putchar(str[index]);
		index++;
	}
	ft_print_nbr(info, str);
	//print_nbr(info, str, len); faire un pont ici pour annalyse des données et ensuite imprimer
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
		info->conversion_specifier = 'x';
	}
	if (s == 'x')
		info->conversion_specifier = 'x';
	if (s == 'X')
		info->conversion_specifier = 'X';
	if (s == 'o')
		info->conversion_specifier = 'o';
	if (s == 'u')
		info->conversion_specifier = 'u';
		//Take number space.
}

void		ft_print_nbr_for_conv(char *str, va_list ap, t_info *info)
{
	unsigned long long	nbr_1;
	long long			nbr_2;

	str = ft_get_info_for_flag(info, str);
	str = ft_get_field_width(info, str, ap);
	get_take_for_convert(*str, info);
	if (info->conversion_specifier == 'd')
		nbr_2 = va_arg(ap, int);
	else
		nbr_1 = va_arg(ap, unsigned int);	
	if (info->conversion_specifier == 'd')
		print_result_d(nbr_2, info, 10);
	else if (info->conversion_specifier == 'u')
		print_result(nbr_1, info, 10);
	else if (info->conversion_specifier == 'o')
		print_result(nbr_1, info, 8);
	else if (info->conversion_specifier == 'x')
		print_result(nbr_1, info, 16);
	else if (info->conversion_specifier == 'X')
		print_result_capx(nbr_1, info, 16);
}
