/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_specifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:19:49 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/01/21 15:26:48 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_specifier(char **format, t_tags *tags, va_list args)
{
	t_spec_to_func	spec_table[] = {{'c', print_c}};

	tags->specifier = **format;
	(*format)++;
	if (tags->specifier == spec_table[0].specifier)
		spec_table[0].function(tags, args);
}