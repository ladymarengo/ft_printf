#include <stdio.h>
char	*ft_itoa_base(int n, int base);


int main()
{
	short unsigned int i = -255;
	printf("%s %o\n", ft_itoa_base(i, 8), i);
	return (0);
}