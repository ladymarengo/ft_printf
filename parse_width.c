/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:13:17 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/02/03 18:15:41 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_width(char **format, t_tags *tags)
{
	tags->width = ft_atoi(*format);
	while (**format >= '0' && **format <= '9')
		(*format)++;
}
