/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_left_or_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:35:14 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/01/27 13:04:57 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	subtract_format(t_tags *tags, int *add, char *str)
{
	if (tags->specifier == 'o' && ft_strcmp(str, "0") != 0)
		*add -= 1;
	else if (ft_tolower(tags->specifier) == 'x' && (ft_strcmp(str, "0") != 0 && ft_strcmp(str, "") != 0))
		*add -= 2;
}

void	add_format(t_tags *tags, char **str, int *chars)
{
	if (tags->hash == 1)
	{
		if (tags->specifier == 'o' && ft_strcmp(*str, "0") != 0)
		{
			ft_putstr("0");
			*chars += 1;
		}
		else if (tags->specifier == 'x' && (ft_strcmp(*str, "0") != 0 && ft_strcmp(*str, "") != 0))
		{
			ft_putstr("0x");
			*chars += 2;
		}
		else if (tags->specifier == 'X' && (ft_strcmp(*str, "0") != 0 && ft_strcmp(*str, "") != 0))
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

void	print_left(char **str, t_tags *tags, int *chars, int blank)
{
	add_format(tags, str, chars);
	if (tags->specifier == 'c')
		ft_putchar(**str);
	else
		ft_putstr(*str);
	fill_space(tags, blank);
	*chars += ft_strlen(*str);
	if (blank > 0)
		*chars += blank;
}

void	print_right(char **str, t_tags *tags, int *chars, int blank)
{
	char	*copy;
	
	copy = *str;
	if (tags->zero == 1 && (*copy == '-' || *copy == '+'))
	{
		ft_putchar(*copy);
		copy++;
		*chars += 1;
	}
	if (tags->zero == 1)
		add_format(tags, &copy, chars);
	fill_space(tags, blank);
	if (tags->zero == 0)
		add_format(tags, &copy, chars);
	if (tags->specifier == 'c')
		ft_putchar(**str);
	else
		ft_putstr(copy);
	*chars += ft_strlen(copy);
	if (blank > 0)
		*chars += blank;
	if (tags->specifier == 'c' && ft_strlen(copy) == 0)
		*chars += 1;
}

void	print_left_or_right(char **str, t_tags *tags, int *chars)
{
	int		blank;

	blank = tags->width - (int) ft_strlen(*str);
	if (tags->specifier == 'c')
		blank = tags->width - 1;
	if (tags->hash == 1)
		subtract_format(tags, &blank, *str);
	if (tags->minus == 1)
		print_left(str, tags, chars, blank);
	else
		print_right(str, tags, chars, blank);
}