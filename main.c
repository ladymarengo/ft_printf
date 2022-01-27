#include "ft_printf.h"
#include <stdio.h>

int main()
{
	unsigned int i = 42;
	ft_printf("Hello world%%\n");
	ft_printf("|%.10p|\n", 0);
	printf("|%.10p|\n", 0);
	return (0);
}