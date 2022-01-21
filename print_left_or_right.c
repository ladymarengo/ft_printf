/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_left_or_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:35:14 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/01/21 15:08:29 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_space(t_tags *tags, int amount)
{
	char	fill;
	
	fill = ' ';
	if (tags->zero == 1 && tags->minus == 0 && tags->specifier != 'c'
		&& tags->specifier != 's' && tags->specifier != 'p')
		fill = '0';
	while (amount > 0)
	{
		ft_putchar(fill);
		amount--;
	}
}

void	print_left_or_right(char *str, t_tags *tags)
{
	size_t	len;

	len = ft_strlen(str);
	if (tags->minus == 1)
	{
		ft_putstr(str);
		fill_space(tags, tags->width - (int) len);
	}
	else
	{
		fill_space(tags, tags->width - (int) len);
		ft_putstr(str);
	}
}