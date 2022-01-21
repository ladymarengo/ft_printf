/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:02:20 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/01/21 15:24:02 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_tags(t_tags *tags)
{
	if (ft_strlen(tags->length) > 0)
		free(tags->length);
	free(tags);
}

void	initialize_tags_to_zero(t_tags *tags)
{
	tags->hash = 0;
	tags->zero = 0;
	tags->minus = 0;
	tags->plus = 0;
	tags->space = 0;
	tags->width = 0;
	tags->precision = 0;
	tags->length = "";
	tags->specifier = 0;
}

void	print_argument(char **format, va_list args)
{
	t_tags	*tags;
	
	tags = malloc(sizeof(t_tags));
	if (!tags)
		exit(-1);
	initialize_tags_to_zero(tags);
	(*format)++;
	parse_flags(format, tags);
	parse_width(format, tags);
	parse_precision(format, tags);
	parse_length(format, tags);
	print_specifier(format, tags, args);
	free_tags(tags);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		chars;
	char	*f_pointer;

	f_pointer = (char *) format;
	chars = 0;
	va_start(args, format);
	while (*f_pointer)
	{
		if (*f_pointer == '%' && *(f_pointer + 1) != '%')
			print_argument(&f_pointer, args);
		else
		{
			if (*f_pointer == '%' && *(f_pointer + 1) == '%')
				f_pointer++;
			ft_putchar(*f_pointer);
			chars++;
			f_pointer++;
		}
	}
	va_end(args);
	return (chars);
}