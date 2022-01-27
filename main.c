#include "ft_printf.h"
#include <stdio.h>

int main()
{
	unsigned int i = 42;
	ft_printf("Hello world%%\n");
	ft_printf("|%05d|\n", -5);
	printf("|%05d|\n", -5);
	return (0);
}