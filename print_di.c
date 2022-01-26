/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 13:52:11 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/01/26 14:17:57 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_di(t_tags *tags, va_list args, int *chars)
{
	intmax_t	number;
	char		*str;

	if (ft_strcmp(tags->length, "hh") == 0)
		number = (signed char)va_arg(args, int);
	else if (ft_strcmp(tags->length, "h") == 0)
		number = (short)va_arg(args, int);
	else if (ft_strcmp(tags->length, "ll") == 0)
		number = (long long)va_arg(args, long long);
	else if (ft_strcmp(tags->length, "l") == 0)
		number = (long)va_arg(args, long);
	else
		number = (int)va_arg(args, int);
	str = ft_itoa(number);
	print_left_or_right(str, tags, chars);
	free(str);
}