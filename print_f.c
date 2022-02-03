/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:19:13 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/02/03 15:36:18 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	round_up(char* str, int i)
{
	if (str[i] == '.')
		round_up(str, i - 1);
	else if (str[i] + 1 <= '9')
		str[i] += 1;
	else if (str[i] == '9')
	{
		str[i] = '0';
		round_up(str, i - 1);
	}
}

void	ft_reverse(char* str, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	j = len - 1;
    while (i < j)
	{
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
		base--;
		result = result * n;
	}
	return (result);
}

int int_to_str(int64_t n, char str[], int d)
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
    ft_reverse(str, i);
	while (i < d)
        str[i++] = '0';
    str[i] = '\0';
    return i;
}
  
void ftoa(long double n, char* res, int afterpoint, int other_aft)
{
    int64_t ipart = (long long)n;
	int i = 0;
	
    long double fpart = n - (long double)ipart;
	if (fpart < 0)
		fpart = -fpart;
	
	if (ipart == 0)
	{
		res[0] = '0';
		i++;
	}
	else
    	i = int_to_str(ipart, res, 0);

	if (afterpoint > 0)
	{
		res[i] = '.';
		i++;
	}

	while (afterpoint-- > 0)
	{
		// printf("aft %d %s\n", afterpoint, res);
		fpart *= 10.0;
		res[i++] = ((unsigned int)fpart % 10) + '0';
		// printf("char %c\n", ((unsigned int)fpart % 10) + '0');
		fpart = fpart - (unsigned int)fpart;
	} 
	// printf("temp %LF\n", res[i - 1]);
	if (fpart - (long double)(int64_t)fpart >= 0.5 && (res[i - 1] + 1 >= '5' || other_aft == 0))
	{
		// printf("yes\n");
		round_up(res, i - 1);
	}
    // if (afterpoint != 0) {
    //     res[i] = '.';
  
	// 	if (afterpoint > 19)
	// 		fpart = fpart * ft_power(10, 19);
	// 	else
    //     	fpart = fpart * ft_power(10, afterpoint);
  
    //     int_to_str((int64_t)fpart, res + i + 1, afterpoint);
	// 	if (fpart - (long double)(int64_t)fpart >= 0.5 && res[i + afterpoint] + 1 >= '5')
	// 		res[i + afterpoint] += 1;		
    // }
	
}

void	print_f(t_tags *tags, va_list args, int *chars)
{
	long double number;
	char	*str;
	
	str = ft_strnew(60);
	if (ft_strcmp(tags->length, "L") == 0)
		number = (long double)va_arg(args, long double);
	else
		number = (double)va_arg(args, double);
	if (tags->precision == -1)
		tags->precision = 6;
	// printf("prec is %d\n", tags->precision);
	ftoa(number, str, tags->precision, tags->precision);
	print_left_or_right(&str, tags, chars);
	free(str);
}