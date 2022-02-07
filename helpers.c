/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:20:08 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/02/07 12:09:03 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	subtract_format(t_tags *tags, int *add, char *str)
{
	if ((tags->specifier == 'o' && str[0] != '0')
		|| (tags->precision == 0 && tags->specifier == 'f'))
		*add -= 1;
	else if ((ft_tolower(tags->specifier) == 'x'
			&& (ft_strcmp(str, "0") != 0 && ft_strcmp(str, "") != 0))
		|| (tags->specifier == 'p' && ft_strcmp(str, "(nil)") != 0))
		*add -= 2;
}

void	add_format(t_tags *tags, char **str, int *chars)
{
	if (tags->hash == 1 || tags->specifier == 'p')
	{
		if (tags->specifier == 'o' && str[0][0] != '0')
		{
			ft_putstr("0");
			*chars += 1;
		}
		else if (((tags->specifier == 'x' || tags->specifier == 'X')
				|| (tags->specifier == 'p' && ft_strcmp(*str, "(nil)") != 0))
			&& (ft_strcmp(*str, "0") != 0 && ft_strcmp(*str, "") != 0))
		{
			*chars += 2;
			if (tags->specifier == 'x' || tags->specifier == 'p')
				ft_putstr("0x");
			else if (tags->specifier == 'X')
				ft_putstr("0X");
		}
		else if (tags->precision == 0 && tags->specifier == 'f')
		{
			ft_putstr(".");
			*chars += 1;
		}
	}
}

int	number_with_precision(t_tags *tags)
{
	if (tags->precision != -1 && (tags->specifier == 'd'
			|| tags->specifier == 'i' || tags->specifier == 'o'
			|| tags->specifier == 'u' || tags->specifier == 'x'
			|| tags->specifier == 'X'))
		return (1);
	else
		return (0);
}

int	is_sign(char c)
{
	if (c == '-' || c == '+' || c == ' ')
		return (1);
	else
		return (0);
}
