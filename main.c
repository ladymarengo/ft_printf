#include "ft_printf.h"
#include <stdio.h>

int main()
{
	short int i = 10000;
	ft_printf("Hello world%%\n");
	ft_printf("|%hhd|\n", i);
	printf("|%hhd|\n", i);
	return (0);
}