/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_length.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:26:17 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/01/19 16:25:07 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	parse_length(char **format, t_tags *tags)
{
	char	possible_length[5][3] = {"hh", "h", "ll", "l", 0};
	int i;

	i = 0;
	while (i < 4)
	{
		if (ft_strncmp(*format, possible_length[i], ft_strlen(possible_length[i])) != 0)
		{
			tags->length = ft_strdup(possible_length[i]);
			i = 0;
			while (i < ft_strlen(tags->length))
			{
				(*format)++;
				i++;
			}
			return ;
		}
		i++;
	}
}