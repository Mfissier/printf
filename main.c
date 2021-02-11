#include "./Includes/ft_printf.h"

int main(void)
{
	printf("ft_printf nbr = %d\n", ft_printf("%d\n", 12345));
	printf("printf nbr = %d\n", printf("%d\n", 12345));

	return(0);
}
