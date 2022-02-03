/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_toupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:46:53 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/02/03 18:09:53 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_toupper(char	*str)
{
	while (*str)
	{
		if (*str >= 97 && *str <= 122)
			*str -= 32;
		str++;
	}
}