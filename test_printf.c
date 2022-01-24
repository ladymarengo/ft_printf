#include <stdio.h>
char	*ft_itoa_base(int n, int base);


int main()
{
	printf("%s %o\n", ft_itoa_base(-255, 8), -255);
	return (0);
}