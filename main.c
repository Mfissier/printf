#include "./Includes/ft_printf.h"

int main(void)
{
	int c = 1;

	printf("nbr ft_printf = %d\n", ft_printf("this %p number", &c));
	printf("nbr printf = %d\n", printf("this %p number", &c));

	printf("conv %ld\n", 140732771293608);
	printf("conv %ld\n", 3872872872);
	
	int i = 111;
	//TEST
/*	
	printf("%-20.4d\n", 111);
	//0111................
	printf("%05d\n", 111)
	//..111
	printf("%*.10d\n", 5, 1);
	//0000000001
	printf("%-20d\n", 111);
*/	
	return(0);
}
