#include "../Includes/ft_printf.h"

void	ft_putstr_test(char *str)
{
	int i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
