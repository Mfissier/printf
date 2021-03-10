#include "./Includes/ft_printf.h"

void ft_print_pt(t_info *info, char *str)
{
	int i;
	int ln;

	while (*str)
	{
		if (*str == '*')
			str++;
		else 
			break;
	}
	ln = (int)ft_strlen(str);
//	if (info->isp == 1)
//		ln -= 2;
	i = -1;
	if (info->pt_n == 1)
	{
		if (info->sign == 1)
			info->count += ft_putchar('-');
		if (info->isp == 1)
		{
			info->count += ft_putchar('0');
			info->count += ft_putchar('x');
		}
		while (++i < info->field_width_next - ln)
			info->count += ft_putchar('0');
		while (*str)
			info->count += ft_putchar(*(str++));
	}
	else if (info->n_pt == 1)
	{
		if (info->isp == 1)
			ln += 2;
		while (++i < info->field_width - ln)
			info->count += ft_putchar(' ');
		if (info->isp == 1)
		{
			info->count += ft_putchar('0');
			info->count += ft_putchar('x');
		}
		while (*str)
			info->count += ft_putchar(*(str++));

	}
	else if (info->n_pt_n == 1)
	{
		if (info->flag->minus != '-')
		{
			if (info->sign == 1)
				i++;
			if (info->field_width_next < ln)
				info->field_width_next = ln;
			if (info->isp == 1)
				i += 2;
			while (++i < ((info->field_width - ln) - (info->field_width_next - ln)))
				info->count += ft_putchar(' ');
			i = -1;
			if (info->sign == 1)
				info->count += ft_putchar('-');
			if (info->isp == 1)
			{
				info->count += ft_putchar('0');
				info->count += ft_putchar('x');
			}
			while (++i < (info->field_width_next - ln))	
				info->count += ft_putchar('0');
			while (*str)
				info->count += ft_putchar(*(str++));
		}
		else
		{
			if (info->sign == 1)
				info->count += ft_putchar('-');
			if (info->isp == 1)
			{
				info->count += ft_putchar('0');
				info->count += ft_putchar('x');
			}
			if (info->field_width_next < ln)
				info->field_width_next = ln;
			while (++i < (info->field_width_next - ln))	
				info->count += ft_putchar('0');
			i = -1;
			if (info->sign == 1)
				i++;
			while (*str)
				info->count += ft_putchar(*(str++));
			while (++i < (info->field_width - info->field_width_next))
				info->count += ft_putchar(' ');
		}

	}

}

void	ft_print_nbr(t_info *info, char *str)
{
	int i;
	int ln;

	i = -1;
	ln = 0;
	if (info->sign == 1)
		ln++;
	if (info->iszero == 1)
		ln++;
	while (str[++i])
	{
		if (str[i] != '*')
			ln++;
	}
	i = 0;
	if (info->n_pt == 1 || info->pt_n == 1 || info->n_pt_n == 1)
	{
		ft_print_pt(info, str);
		return;
	}
	if (info->flag->minus == '-')
	{
		if (info->sign == 1)
			info->count += ft_putchar('-');
		if (info->iszero == 1)
			info->count += ft_putchar('0');
		if (info->isp == 1)
		{
			info->count += ft_putchar('0');	
			info->count += ft_putchar('x');	
			ln += 2;
		}
		while (*str)
		{
			if (*str != '*')
				info->count += ft_putchar(*str);
			str++;
		}
		while (i++ < info->field_width - ln)
			info->count += ft_putchar(' ');
	}
	else
	{
		if (info->isp == 1)
			ln += 2;
		if (info->flag->zero == 'y')
		{
			if (info->sign == 1)
				info->count += ft_putchar('-');
			while (i++ < info->field_width - ln)
				info->count += ft_putchar('0');
		}
		if (info->flag->zero != 'y')
			while (i++ < info->field_width - ln)
				info->count += ft_putchar(' ');
		if (info->sign == 1 && info->flag->zero != 'y')
			info->count += ft_putchar('-');
		if (info->isp == 1)
		{
			info->count += ft_putchar('0');	
			info->count += ft_putchar('x');	
		}
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
