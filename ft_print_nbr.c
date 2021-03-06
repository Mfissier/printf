#include "./Includes/ft_printf.h"
		
void ft_print_pt(t_info *info, char *str)
{
	int i;
	int ln;

	while(*str)
	{
		if (*str == '*')
			str++;
		else 
			break;
	}
	ln = (int)ft_strlen(str);
	i = -1;
	if (info->pt_n == 1)
	{
		while (++i < info->field_width_next - ln)
			info->count += ft_putchar('0');
		while (*str)
			info->count += ft_putchar(*(str++));
	}
	else if (info->n_pt == 1)
	{
		while (++i < info->field_width - ln)
			info->count += ft_putchar(' ');
		while (*str)
			info->count += ft_putchar(*(str++));
	
	}
	else if (info->n_pt_n == 1)
	{
		while (++i < ((info->field_width - ln) - (info->field_width_next - ln)))
			info->count += ft_putchar(' ');
		i = -1;
		while (++i < (info->field_width_next - ln))	
			info->count += ft_putchar('0');
		while (*str)
			info->count += ft_putchar(*(str++));
	}

}

void	ft_print_nbr(t_info *info, char *str)
{
	int i;
	int ln;

	i = -1;
	ln = 0;
	while(str[++i])
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
		while (*str)
		{
			if (*str != '*')
				info->count += ft_putchar(*str); 
			str++;
		}
		while (ln++ < info->field_width)
			info->count += ft_putchar(' ');
	} 
	else
	{
		while (ln++ < info->field_width)
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
