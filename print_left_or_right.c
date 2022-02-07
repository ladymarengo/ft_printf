/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_left_or_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:35:14 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/02/07 12:09:28 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_space(t_tags *tags, int amount)
{
	char	fill;

	fill = ' ';
	if (tags->zero == 1 && tags->minus == 0 && tags->specifier != 'c'
		&& tags->specifier != 's' && (tags->precision == -1
			|| (tags->precision == 0 && tags->specifier == 'f')))
		fill = '0';
	while (amount > 0)
	{
		ft_putchar(fill);
		amount--;
	}
}

void	print_left(char **str, t_tags *tags, int *chars, int blank)
{
	if (tags->specifier != 'f')
		add_format(tags, str, chars);
	if (tags->specifier == 'c')
		ft_putchar(**str);
	else
		ft_putstr(*str);
	if (tags->specifier == 'f')
		add_format(tags, str, chars);
	fill_space(tags, blank);
	*chars += ft_strlen(*str);
	if (blank > 0)
		*chars += blank;
}

void	print_right(char **str, t_tags *tags, int *chars, int blank)
{
	char	*copy;

	copy = *str;
	if (tags->zero == 1 && is_sign(*copy) && number_with_precision(tags) == 0)
	{
		ft_putchar(*copy);
		copy++;
		*chars += 1;
	}
	if (tags->zero == 1 && tags->specifier != 'f')
		add_format(tags, &copy, chars);
	fill_space(tags, blank);
	if (tags->zero == 0 && tags->specifier != 'f')
		add_format(tags, &copy, chars);
	if (tags->specifier == 'c')
		ft_putchar(**str);
	else
		ft_putstr(copy);
	if (tags->specifier == 'f')
		add_format(tags, &copy, chars);
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
	if (tags->hash == 1 || tags->specifier == 'p')
		subtract_format(tags, &blank, *str);
	if (tags->minus == 1)
		print_left(str, tags, chars, blank);
	else
		print_right(str, tags, chars, blank);
	free(*str);
}
