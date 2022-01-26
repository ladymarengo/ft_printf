/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_oux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:39:55 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/01/26 18:10:25 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	subtract_format(t_tags *tags, int *add)
{
	if (tags->specifier == 'o')
		*add -= 1;
	else if (ft_tolower(tags->specifier) == 'x')
		*add -= 2;
}

void	handle_u_precision(t_tags *tags, char **str, uintmax_t number)
{
	int		add;
	char	*add_str;
	char	*temp;

	if (tags->precision >= 0)
	{
		add = tags->precision - ft_strlen(*str);
		subtract_format(tags, &add);
		if (add > 0)
		{
			add_str = ft_strnew(add);
			ft_memset(add_str, '0', add);
			temp = ft_strjoin(add_str, *str);
			free(*str);
			free(add_str);
			*str = temp;
		}
		if (tags->precision == 0 && number == 0)
		{
			free(*str);
			*str = ft_strdup("");
		}
	}
}

void	format_string(t_tags *tags, char **str, uintmax_t number)
{
	char	*add;
	char	*temp;
	
	if (tags->hash == 1 && number != 0 && tags->specifier != 'u')
	{
		if (tags->specifier == 'o')
			add = ft_strdup("0");
		else if (tags->specifier == 'x')
			add = ft_strdup("0x");
		else if (tags->specifier == 'X')
			add = ft_strdup("0X");
		temp = ft_strjoin(add, *str);
		free(*str);
		free(add);
		*str = temp;
	}
}

void	print_oux(t_tags *tags, va_list args, int *chars)
{
	uintmax_t	number;
	char		*str;

	if (ft_strcmp(tags->length, "hh") == 0)
		number = (unsigned char)va_arg(args, unsigned int);
	else if (ft_strcmp(tags->length, "h") == 0)
		number = (unsigned short)va_arg(args, unsigned int);
	else if (ft_strcmp(tags->length, "ll") == 0)
		number = (unsigned long long)va_arg(args, unsigned long long);
	else if (ft_strcmp(tags->length, "l") == 0)
		number = (unsigned long)va_arg(args, unsigned long);
	else
		number = (unsigned int)va_arg(args, unsigned int);
	if (tags->specifier == 'u')
		str = ft_itoa_base(number, 10);
	else if (tags->specifier == 'o')
		str = ft_itoa_base(number, 8);
	else if (ft_tolower(tags->specifier) == 'x')
		str = ft_itoa_base(number, 16);
	if (tags->specifier == 'X')
		ft_str_toupper(str);
	handle_u_precision(tags, &str, number);
	format_string(tags, &str, number);
	print_left_or_right(str, tags, chars);
	free(str);
}