/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_left_or_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:35:14 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/01/26 16:17:18 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	print_left_or_right(char *str, t_tags *tags, int *chars)
{
	size_t	len;
	int		blank;

	len = ft_strlen(str);
	blank = tags->width - (int) len;
	if (tags->minus == 1)
	{
		ft_putstr(str);
		fill_space(tags, blank);
	}
	else
	{
		fill_space(tags, blank);
		ft_putstr(str);
	}
	*chars =+ len;
	if (blank > 0)
		*chars =+ blank;
}