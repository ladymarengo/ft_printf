#include "ft_printf.h"
#include <stdio.h>

int main()
{
	unsigned int i = 42;
	ft_printf("Hello world%%\n");
	ft_printf("|% |\n");
	printf("|% |\n");
	return (0);
}