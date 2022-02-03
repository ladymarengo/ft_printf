/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:19:49 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/02/03 18:21:43 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_specifier(char **format, t_tags *tags, va_list args, int *chars)
{
	tags->specifier = **format;
	(*format)++;
	if (tags->specifier == 'c')
		print_c(tags, args, chars);
	else if (tags->specifier == 's')
		print_s(tags, args, chars);
	else if (tags->specifier == 'd' || tags->specifier == 'i')
		print_di(tags, args, chars);
	else if (tags->specifier == 'o' || tags->specifier == 'u'
		|| ft_tolower(tags->specifier) == 'x' || tags->specifier == 'p')
		print_poux(tags, args, chars);
	else if (tags->specifier == 'f')
		print_f(tags, args, chars);
	else if (tags->specifier == '%')
	{
		ft_putchar('%');
		*chars += 1;
	}
}
