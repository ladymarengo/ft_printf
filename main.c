#include "ft_printf.h"

int main()
{
	ft_printf("Hello world%%\n");
	ft_printf("Here come flags: %0-+ #123.456hhcdone\n", 50);
	return (0);
}