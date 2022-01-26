#include "ft_printf.h"
#include <stdio.h>

int main()
{
	unsigned int i = 42;
	ft_printf("Hello world%%\n");
	ft_printf("|%#-5X|\n", i);
	printf("|%#-5X|\n", i);
	return (0);
}