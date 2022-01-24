/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:24:39 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/01/21 15:57:24 by nsamoilo         ###   ########.fr       */
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
	void	(*function)(t_tags *tags, va_list args);
} t_spec_to_func;

int		ft_printf(const char *format, ...);
void	free_tags(t_tags *tags);
void	parse_flags(char **format, t_tags *tags);
void	parse_width(char **format, t_tags *tags);
void	parse_precision(char **format, t_tags *tags);
void	parse_length(char **format, t_tags *tags);
void	print_specifier(char **format, t_tags *tags, va_list args, int *chars);
void	print_left_or_right(char *str, t_tags *tags, int *chars);
void	print_c(t_tags *tags, va_list args, int *chars);
void	print_s(t_tags *tags, va_list args, int *chars);
void	print_p(t_tags *tags, va_list args, int *chars);

#endif