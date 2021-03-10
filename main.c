#include "./Includes/ft_printf.h"

int main(void)
{
	int c = 0;
	int c1 = 1;
	int c2 = 1;
	int c3 = 1;

	printf("V%-32p,%-32p,%-32p, %-32p\n", &c, &c1, &c2, &c3);
	ft_printf("F%-32p,%-32p,%-32p, %-32p\n", &c, &c1, &c2, &c3);
	return(0);
}
