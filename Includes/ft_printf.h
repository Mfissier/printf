#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "../libft/libft.h"

typedef struct	s_info
{
	int count;  
}		t_info;
int		ft_printf(const char *contain, ...);
char		*ft_print_result(char *str, va_list ap, t_info *info);


#endif

