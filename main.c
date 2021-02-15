#include "./Includes/ft_printf.h"

int main(void)
{
	ft_printf("%10d", 111);
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
