#include "./Includes/ft_printf.h"

int main(void)
{
	int c = 1;

//	printf("nbr ft_printf = %d\n", ft_printf("this %-5% number"));
	//printf("nbr printf = %d\n", printf("this %-5%"));
 //	printf("p = %d\n", ft_printf("%s123\n", "bonhjour"));	
 //	printf("p = %d\n", printf("%s123\n", "bonhjour"));	
//	printf("%d", printf("%s", NULL));
//	printf("%d", ft_printf("%s", NULL));

	
	//	printf("%%10.d = %10.d\n", 123);
	//	printf("p%d => ", printf("%%.3d = %10.8d\n", 123));
		printf("p) %10.8d\n", 123);
		ft_printf("ft) %10.8d\n", 123);

	//	printf("ft%d => ", ft_printf("%%.3d = %10.10d\n", 123));
	//	printf("%%10.10d = %10.10d\n", 5);
	//	printf("%%10.d = %10.d\n", 5);
	//	printf("%%-10.d = %-10.d\n", 123);
	//	printf("%%-10.10d = %-10.10d\n", 5);
	//	printf("%%-.10d = %-.10d\n", 5);
//	printf("%%.13d", 12345);
	int i = 111;
	//TEST
/*	
	printf("%-20.4d\n", 111);
	//0111................
	printf("%05d\n", 111)
	//..111
	//0000000001
	printf("%-20d\n", 111);
*/	
	return(0);
}
