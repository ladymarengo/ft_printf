/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:34:27 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/01/21 15:26:51 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(t_tags *tags, va_list args)
{
	char	*c;
	
	c = ft_strnew(1);
	if (!c)
	{
		free_tags(tags);
		exit(-1);
	}
	c[0] = (char)va_arg(args, int);
	print_left_or_right(c, tags);
	free(c);
}