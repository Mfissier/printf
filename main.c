#include "./Includes/ft_printf.h"

int main(void)
{
//	printf("nbr ft_printf = %d\n",ft_printf("%-10d\n", 111));
//	printf("nbr printf = %d\n", printf("%-10d\n", 111)); 

	printf("nbr ft_printf = %d\n", ft_printf("f**%10d*\n", 1000));
	printf("nbr printf = %d\n", printf("p**%10d*\n", 1000));
	
	int i = 111;
	//TEST
/*	
	printf("%-20.4d\n", 111);
	//0111................
	printf("%05d\n", 111);
	//..111
	printf("%*.10d\n", 5, 1);
	//0000000001
	printf("%-20d\n", 111);
*/	
	return(0);
}
