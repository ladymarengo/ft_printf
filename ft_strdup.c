/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 11:19:02 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/01/26 14:11:19 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(char const *s1)
{
	char	*new;

	new = ft_strnew(ft_strlen(s1));
	if (new == NULL)
		return (NULL);
	ft_strcpy(new, s1);
	return (new);
}
