/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:38:46 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/01/26 13:55:20 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	count_digits(intmax_t ln)
{
	int	digits;

	digits = 1;
	if (ln < 0)
	{
		digits++;
		ln = -ln;
	}
	while (ln >= 10)
	{
		digits++;
		ln = ln / 10;
	}
	return (digits);
}

char	*ft_itoa(intmax_t n)
{
	char	*str;
	int		i;

	i = count_digits(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n >= 10)
	{	
		str[i - 1] = '0' + (n % 10);
		i--;
		n = n / 10;
	}
	str[i - 1] = '0' + n;
	return (str);
}
