/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_left_or_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:35:14 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/01/26 19:22:38 by nsamoilo         ###   ########.fr       */
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

int	all_zero(char *str)
{
	while (*str)
	{
		if (*str != '0')
			return (0);
		str++;
	}
	return (1);
}

void	add_format(t_tags *tags, char **str, int *chars)
{
	if (tags->hash == 1 && all_zero(*str) == 0)
	{
		if (tags->specifier == 'o')
		{
			ft_putstr("0");
			*chars += 1;
		}
		else if (tags->specifier == 'x')
		{
			ft_putstr("0x");
			*chars += 2;
		}
		else if (tags->specifier == 'X')
		{
			ft_putstr("0X");
			*chars += 2;
		}
	}
}

void	fill_space(t_tags *tags, int amount)
{
	char	fill;
	
	fill = ' ';
	if (tags->zero == 1 && tags->minus == 0 && tags->specifier != 'c'
		&& tags->specifier != 's' && tags->specifier != 'p' && tags->precision == -1)
		fill = '0';
	while (amount > 0)
	{
		ft_putchar(fill);
		amount--;
	}
}

void	print_left_or_right(char **str, t_tags *tags, int *chars)
{
	int		blank;

	blank = tags->width - (int) ft_strlen(*str);
	if (tags->hash == 1)
		subtract_format(tags, &blank);
	if (tags->zero == 1)
		add_format(tags, str, chars);
	if (tags->minus == 1)
	{
		if (tags->zero == 0)
			add_format(tags, str, chars);
		ft_putstr(*str);
		fill_space(tags, blank);
	}
	else
	{
		fill_space(tags, blank);
		if (tags->zero == 0)
			add_format(tags, str, chars);
		ft_putstr(*str);
	}
	*chars += ft_strlen(*str);
	if (blank > 0)
		*chars += blank;
}