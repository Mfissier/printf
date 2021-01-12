#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../libft/libft.h"
int ft_printf(const char *str, ...);
void	ft_putstr_test(char *str);

typedef struct	s_env
{
	const char	*str;
	size_t		cur;
	char		flag[5];
	int			size;
	int			dot;
	int			precision;
	char		modif[6];
	char		conv;
	size_t		printcar;
	int			len;
	int			ret;
	void		*argum;
}				t_env;

#endif

