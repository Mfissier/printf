#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../libft/libft.h"

typedef struct		s_string
{
	int		precision;
	int		is_char;
	char	chara;
	wchar_t	wchara;
}					t_string;

typedef struct   s_flag_info
{
	char	hash;
	char	minus;
	char	plus;
	char	space;
	char	zero;
}		t_flag_info;

typedef struct	s_info
{
	int		field_width;
	int		precision;
	char		conversion_specifier;
	char		len_mod[3];
	char		pre_sign[3];
	int		count;
	int		iszero;
	int		is_nopre;
	int		is_dot;
	int		is_dot_zero;
	int		is_dot_pre;
	int		isp;
	int		sign;
	char		star;
	t_flag_info *flag;
}		t_info;

int		ft_printf(const char *contain, ...);
char		*ft_print_result(char *str, va_list ap, t_info *info);
void		ft_print_nbr_for_conv(char *str, va_list ap, t_info *info);
char		*ft_get_info_for_flag(t_info *info, char *str);
char		*ft_get_field_width(t_info *info, char *str, va_list ap);
void		ft_print_string_for_conv(char *str, va_list ap, t_info *info);
void		ft_print_nbr(t_info *info, char *str);

#endif

