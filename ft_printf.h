/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:24:39 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/01/19 13:26:35 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_tags
{
	int		hash;
	int		zero;
	int		minus;
	int		plus;
	int		space;
	int		width;
	int		precision;
	char	*length;
	char	specifier;
} t_tags;

int		ft_printf(const char *format, ...);
void	parse_flags(char **format, t_tags *tags);
void	parse_width(char **format, t_tags *tags);
void	parse_precision(char **format, t_tags *tags);
void	parse_length(char **format, t_tags *tags);

#endif