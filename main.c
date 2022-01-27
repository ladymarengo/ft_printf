#include "ft_printf.h"
#include <stdio.h>

int main()
{
	unsigned int i = 42;
	ft_printf("Hello world%%\n");
	ft_printf("|%0.28p|\n", &i);
	printf("|%0.28p|\n", &i);
	return (0);
}