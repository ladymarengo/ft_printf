/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:19:13 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/02/02 17:21:37 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

long long	ft_power(int n, int base)
{
	long long	result;
	
	result = 1;
	while (base > 0)
	{
		base++;
		result = result * n;
	}
	return (n);
}

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
  
void ftoa(long double n, char* res, int afterpoint)
{
    int64_t ipart = (long long)n;
  
    long double fpart = n - (long double)ipart;
	if (fpart < 0)
		fpart = -fpart;
  
    int i = intToStr(ipart, res, 0);
  
    if (afterpoint != 0) {
        res[i] = '.';
  
		if (afterpoint > 19)
			fpart = fpart * ft_power(10, 19);
		else
        	fpart = fpart * ft_power(10, afterpoint);
  
        intToStr((int64_t)fpart, res + i + 1, afterpoint);
		
    }
}

void	print_f(t_tags *tags, va_list args, int *chars)
{
	long double number;
	char	*str;
	
	str = (char *)malloc(sizeof(char) * 60);
	if (ft_strcmp(tags->length, "L") == 0)
		number = (long double)va_arg(args, long double);
	else
		number = (double)va_arg(args, double);
	ftoa(number, str, tags->precision);
	print_left_or_right(&str, tags, chars);
	free(str);
}