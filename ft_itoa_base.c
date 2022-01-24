/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 11:04:36 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/01/24 14:53:35 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	base_char(unsigned n)
{
	char	*chars;
	char	c;
	
	chars = ft_strdup("0123456789abcdef");
	c = chars[n];
	free(chars);
	return (c);
}

int	count_digits(unsigned long ln, int base)
{
	int	digits;

	digits = 1;
	while (ln >= base)
	{
		digits++;
		ln = ln / base;
	}
	return (digits);
}

char	*ft_itoa_base(int n, int base)
{
	char	*str;
	int		i;
	unsigned	ln;

	ln = (unsigned) n;
	i = count_digits(ln, base);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	while (ln >= base)
	{	
		str[i - 1] = base_char((ln % base));
		i--;
		ln = ln / base;
	}
	str[i - 1] = base_char((ln % base));
	return (str);
}