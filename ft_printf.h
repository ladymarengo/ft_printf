/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:24:39 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/01/19 16:17:28 by nsamoilo         ###   ########.fr       */
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

typedef struct s_spec_to_func
{
	char	specifier;
	void	(*function)(char **format, t_tags *tags, va_list args);
} t_spec_to_func;

int		ft_printf(const char *format, ...);
void	parse_flags(char **format, t_tags *tags);
void	parse_width(char **format, t_tags *tags);
void	parse_precision(char **format, t_tags *tags);
void	parse_length(char **format, t_tags *tags);
void	print_specifier(char **format, t_tags *tags, va_list args);

#endif