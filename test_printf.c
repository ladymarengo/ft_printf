#include <math.h>
#include <stdio.h>
# include <inttypes.h>
  
// Reverses a string 'str' of length 'len'
void reverse(char* str, int len)
{
    int i = 0, j = len - 1, temp;
    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}
  
// Converts a given integer x to string str[]. 
// d is the number of digits required in the output. 
// If d is more than the number of digits in x, 
// then 0s are added at the beginning.
int intToStr(int64_t n, char str[], int d)
{
    int i = 0;
	int64_t x = n;
	if (x < 0)
	{
		x = -x;
	}
    while (x) {
        str[i++] = (x % 10) + '0';
        x = x / 10;
    }
	
	if (n < 0)
		str[i++] = '-';
    reverse(str, i);
	while (i < d)
        str[i++] = '0';
    str[i] = '\0';
    return i;
}
  
// Converts a floating-point/double number to a string.
void ftoa(long double n, char* res, int afterpoint)
{
    // Extract integer part
    int64_t ipart = (long long)n;
  
    // Extract floating part
    long double fpart = n - (long double)ipart;
	if (fpart < 0)
		fpart = -fpart;
  
    // convert integer part to string
    int i = intToStr(ipart, res, 0);
  
	// printf("%lld\n", ipart);
    // check for display option after point
    if (afterpoint != 0) {
        res[i] = '.'; // add dot
  
        // Get the value of fraction part upto given no.
        // of points after dot. The third parameter 
        // is needed to handle cases like 233.007
		if (afterpoint > 19)
			fpart = fpart * pow(10, 19);
		else
        	fpart = fpart * pow(10, afterpoint);
  
        intToStr((int64_t)fpart, res + i + 1, afterpoint);
		
    }
}
  
// Driver program to test above function
int main()
{
    char res[60];
	char res2[60];
    long double n = 6.6465424242242454654;
    ftoa((double) 1444565444646.6465424242242l, res, 6);
	printf("{%f}\n{%lf}\n{%Lf}\n", 1444565444646.6465424242242, 1444565444646.6465424242242, 1444565444646.6465424242242l);
    printf("\"%s\"\n", res);
	printf("{%f}\n{%lf}\n{%Lf}\n", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654, -1444565444646.6465424242242454654l);
	ftoa(-1444565444646.6465424242242454654l, res2, 6);
	printf("\"%s\"\n", res2);

	// long double value = 14444565444646.12345678901234567890777;
    // printf("real: |%.25Lf|\n", 14444565444646.12345678901234567890777);
    return 0;
}

// #include <stdio.h>
// #include <inttypes.h>
// char	*ft_itoa_base(int n, int base);

// void printBinary(intmax_t n, int i)
// {
 
//     // Prints the binary representation
//     // of a number n up to i-bits.
//     int k;
//     for (k = i - 1; k >= 0; k--) {
 
//         if ((n >> k) & 1)
//             printf("1");
//         else
//             printf("0");
//     }
// }
 
// typedef union {
 
//     double f;
//     struct
//     {
 
//         // Order is important.
//         // Here the members of the union data structure
//         // use the same memory (32 bits).
//         // The ordering is taken
//         // from the LSB to the MSB.
//         unsigned long mantissa : 52;
//         unsigned int exponent : 11;
//         unsigned int sign : 1;
 
//     } raw;
// } myfloat;
 
// // Function to convert real value
// // to IEEE floating point representation
// void printIEEE(myfloat var)
// {
 
//     // Prints the IEEE 754 representation
//     // of a float value (32 bits)
 
//     printf("%d | ", var.raw.sign);
//     printBinary(var.raw.exponent, 11);
//     printf(" | ");
//     printBinary(var.raw.mantissa, 52);
//     printf("\n");
// }
 
// // Driver Code
// int main()
// {
 
//     // Instantiate the union
//     myfloat var;
 
//     // Get the real value
//     var.f = 0.1;
 
//  	printf("%lu\n", sizeof(var));
//     // Get the IEEE floating point representation
//     printf("IEEE 754 representation of %f is : \n",
//            var.f);
//     printIEEE(var);
 
//     return 0;
// }