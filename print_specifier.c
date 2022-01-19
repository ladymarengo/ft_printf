/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:19:49 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/01/19 16:26:04 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(char **format, t_tags *tags, va_list args)
{
	ft_putchar((char)va_arg(args, int));
	(*format)++;
}

void	print_specifier(char **format, t_tags *tags, va_list args)
{
	t_spec_to_func	spec_table[] = {{'c', print_c}};

	if (**format == spec_table[0].specifier)
		spec_table[0].function(format, tags, args);
}