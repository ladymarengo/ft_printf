/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:19:13 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/02/04 19:17:09 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_float_sign(t_tags *tags, char **str, long double number)
{
	char	*temp;

	if (number < 0)
	{
		temp = ft_strjoin("-", *str);
		free(*str);
		*str = temp;
	}
	else if (number >= 0 && (tags->plus == 1 || tags->space == 1))
	{
		if (tags->plus == 1)
			temp = ft_strjoin("+", *str);
		else if (tags->space == 1)
			temp = ft_strjoin(" ", *str);
		free(*str);
		*str = temp;
	}
}

void	round_up(char **str, int i)
{
	if ((*str)[i] == '.')
		round_up(str, i - 1);
	else if ((*str)[i] + 1 <= '9')
		(*str)[i] += 1;
	else if ((*str)[i] == '9')
	{
		(*str)[i] = '0';
		round_up(str, i - 1);
	}
}

long double	add_float_part(long double f, char **float_str, int afterpoint)
{
	int		i;

	*float_str = ft_strnew(100);
	i = 0;
	f = f - (long double)(long long)f;
	if (f < 0)
		f = -f;
	if (afterpoint > 0)
	{
		(*float_str)[i] = '.';
		i++;
	}
	while (afterpoint-- > 0)
	{
		f *= 10.0;
		(*float_str)[i++] = ((unsigned int)f % 10) + '0';
		f = f - (unsigned int)f;
	}
	return (f);
}

void	ftoa(long double n, char **str, int precision)
{
	char		*int_part;
	char		*float_part;
	long double	remainder;

	int_part = ft_itoa_without_sign((long long)n);
	remainder = add_float_part(n, &float_part, precision);
	*str = ft_strjoin(int_part, float_part);
	free(int_part);
	free(float_part);
	if ( (remainder * 10.0 - (double)(int64_t)remainder > 5) || (remainder - (double)(int64_t)remainder >= 0.5
		&& ((*str)[ft_strlen((*str)) - 1] + 1 >= '5' || precision == 0)))
		round_up(str, ft_strlen(*str) - 1);
}

void	print_f(t_tags *tags, va_list args, int *chars)
{
	long double	number;
	char		*str;

	if (ft_strcmp(tags->length, "L") == 0)
		number = (long double)va_arg(args, long double);
	else
		number = (double)va_arg(args, double);
	if (tags->precision == -1)
		ftoa(number, &str, 6);
	else
		ftoa(number, &str, tags->precision);
	add_float_sign(tags, &str, number);
	print_left_or_right(&str, tags, chars);
}
