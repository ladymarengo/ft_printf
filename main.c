#include "ft_printf.h"
#include <stdio.h>

int main()
{
	// int i = 1;
	ft_printf("Hello world%%\n");
	ft_printf("|%+s|\n", "hello");
	printf("|%+s|\n", "hello");
	return (0);
}