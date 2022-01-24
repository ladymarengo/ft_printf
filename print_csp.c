/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_csp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:34:27 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/01/24 10:49:17 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(t_tags *tags, va_list args, int *chars)
{
	char	*c;
	
	c = ft_strnew(1);
	if (!c)
	{
		free_tags(tags);
		exit(-1);
	}
	c[0] = (char)va_arg(args, int);
	print_left_or_right(c, tags, chars);
	free(c);
}

void	print_s(t_tags *tags, va_list args, int *chars)
{
	char	*s;
	
	s = (char *)va_arg(args, char *);
	if (!s)
		print_left_or_right("(null)", tags, chars);
	else
		print_left_or_right(s, tags, chars);
}

void	print_p(t_tags *tags, va_list args, int *chars)
{
	// Work In Progress
	print_left_or_right((char *)va_arg(args, char *), tags, chars);
}