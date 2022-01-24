/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:19:49 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/01/21 15:56:42 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_specifier(char **format, t_tags *tags, va_list args, int *chars)
{
	tags->specifier = **format;
	(*format)++;
	if (tags->specifier == 'c')
		print_c(tags, args);
	else if (tags->specifier == 's')
		print_s(tags, args);
	else if (tags->specifier == 'p')
		print_p(tags, args);
}