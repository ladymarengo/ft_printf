/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:02:20 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/01/18 15:30:34 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		chars;

	chars = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '%')
			continue;
		else
		{
			if (*format == '%' && *(format + 1) == '%')
				format++;
			ft_putchar(*format);
			chars++;
			format++;
		}
	}
	va_end(args);
	return (chars);
}