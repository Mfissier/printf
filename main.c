#include "./Includes/ft_printf.h"

int main(void)
{


	printf("%-*.*s\n", -7, -3, "hello");
	ft_printf("%-*.*s\n", -7, -3, "hello");

	printf("%-7s", "hello");

	return(0);
}
