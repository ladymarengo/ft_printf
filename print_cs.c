/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:34:27 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/01/27 13:40:24 by nsamoilo         ###   ########.fr       */
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
	print_left_or_right(&c, tags, chars);
	free(c);
}

void	print_s(t_tags *tags, va_list args, int *chars)
{
	char	*s;
	char	*temp;
	
	s = (char *)va_arg(args, char *);
	if (s == NULL)
	{
		if (tags->precision == -1 || tags->precision > 5)
			s = ft_strdup("(null)");
		else
			s = ft_strdup("");
	}
	else
		s = ft_strdup(s);
	if (tags->precision >= 0)
	{
		temp = ft_strsub(s, 0, tags->precision);
		free(s);
		s = temp;
	}
	print_left_or_right(&s, tags, chars);
	free(s);
}
