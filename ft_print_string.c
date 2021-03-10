#include "./Includes/ft_printf.h"

void ft_print_pt_string(t_info *info, char *str)
{
	int i;
	int ln;
	int count;

	ln = (int)ft_strlen(str);
	count = 0;
	i = -1;
	if (info->pt_n == 1)
	{
		while (*str && info->field_width_next > 0)
		{
			info->count += ft_putchar(*(str++));
			info->field_width_next--;
		}
	}
	else if (info->n_pt == 1)
	{
		while (++i < info->field_width)
			info->count += ft_putchar(' ');
	}
	else if (info->n_pt_n == 1)
	{
		if (info->flag->minus == '-')
		{
			while (*str && info->field_width_next > 0)
			{
				info->count += ft_putchar(*(str++));
				info->field_width_next--;
				count++;
			}
			while (count < info->field_width)
			{
				info->count += ft_putchar(' ');
				info->field_width--;
			}	
		}
		else
		{
			count = info->field_width_next;
			if (info->field_width_next > ln)
				count = ln;
			while(info->field_width - count > 0)
			{
				info->count += ft_putchar(' ');
				count++;	
			}
			count = info->field_width_next;
			if (info->field_width_next > ln)
				count = ln;
			while(*str && count > 0)
			{
				info->count += ft_putchar(*(str++));
				count--;
			}

		}
	}
}

void	ft_print_string(t_info *info, char *str)
{
	int i;
	int ln;

	i = -1;
	ln = ft_strlen(str);
	i = 0;
	if (info->n_pt == 1 || info->pt_n == 1 || info->n_pt_n == 1)
	{
		ft_print_pt_string(info, str);
		return;
	}
	if (info->flag->minus == '-')
	{
		if (info->sign == 1)
			info->count += ft_putchar('-');
		if (info->iszero == 1)
			info->count += ft_putchar('0');
		if (info->char_z == 1)
			ft_putchar('\0');
		while (*str)
		{
			if (*str != '*')
				info->count += ft_putchar(*str); 
			str++;
		}
		if (info->char_z == 1)
			info->field_width--;
		while (ln++ < info->field_width)
			info->count += ft_putchar(' ');
	} 
	else
	{
		if (info->char_z == 1)
			info->field_width--;
		if (info->flag->zero == 'y')
			while (ln++ < info->field_width)
				info->count += ft_putchar('0');
		if (info->flag->zero != 'y')
			while (ln++ < info->field_width)
				info->count += ft_putchar(' ');
		if (info->sign == 1)
			info->count += ft_putchar('-');
		if (info->iszero == 1)
			info->count += ft_putchar('0');
		if (info->char_z == 1)
			info->count += ft_putchar(str[0]);
		while (*str)
			info->count += ft_putchar(*(str++)); 
	}	
}
