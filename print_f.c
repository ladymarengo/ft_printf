/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 14:19:13 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/02/02 15:30:40 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_f(t_tags *tags, va_list args, int *chars)
{
	float	f_number;
	double d_number;
	long double ld_number;
	
	if (ft_strcmp(tags->length, "L") == 0)
	{
		ld_number = (long double)va_arg(args, long double);
	}
	else if (ft_strcmp(tags->length, "l") == 0)
	{
		d_number = (double)va_arg(args, double);
	}
	else
	{
		f_number = (float)va_arg(args, float);
	}
}