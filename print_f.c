/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:19:13 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/02/08 11:12:44 by nsamoilo         ###   ########.fr       */
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
	if (!(*str))
		error_exit(tags, 0);
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

__float128	add_float_part(__float128 f, char **float_str, int afterpoint)
{
	int		i;

	*float_str = ft_strnew(100);
	if (!float_str)
		return (0);
	i = 0;
	f = f - (__float128)(long long)f;
	if (f < 0)
		f = -f;
	if (afterpoint > 0)
	{
		(*float_str)[i] = '.';
		i++;
	}
	while (afterpoint-- > 0)
	{
		f *= (__float128) 10.0;
		(*float_str)[i++] = ((long long)f % 10) + '0';
		f = f - (long long)f;
	}
	return (f);
}

void	ftoa(t_tags *tags, __float128 n, char **str, int precision)
{
	char		*int_part;
	char		*float_part;
	__float128	remainder;
	char		*temp;

	int_part = ft_itoa_without_sign((long long)n);
	remainder = add_float_part(n, &float_part, precision);
	if (!int_part || !float_part)
		error_exit(tags, 2, int_part, float_part);
	*str = ft_strjoin(int_part, float_part);
	free(int_part);
	free(float_part);
	temp = ft_strdup(*str);
	if (!(*str) || !temp)
		error_exit(tags, 2, *str, temp);
	round_up(&temp, ft_strlen(temp) - 1);
	if (1.0 - remainder < 0 + remainder
		|| (1.0 - remainder == 0 + remainder
			&& ((*str)[ft_strlen((*str)) - 1] + 1 - '0') % 2 == 0))
		round_up(str, ft_strlen(*str) - 1);
	free(temp);
}

void	print_f(t_tags *tags, va_list args, int *chars)
{
	__float128	number;
	char		*str;

	if (ft_strcmp(tags->length, "L") == 0)
		number = (long double)va_arg(args, long double);
	else
		number = (double)va_arg(args, double);
	if (tags->precision == -1)
		ftoa(tags, number, &str, 6);
	else
		ftoa(tags, number, &str, tags->precision);
	add_float_sign(tags, &str, number);
	print_left_or_right(&str, tags, chars);
}
