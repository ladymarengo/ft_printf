/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:24:39 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/02/02 14:19:46 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <inttypes.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

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
void	print_left_or_right(char **str, t_tags *tags, int *chars);
void	print_c(t_tags *tags, va_list args, int *chars);
void	print_s(t_tags *tags, va_list args, int *chars);
void	print_di(t_tags *tags, va_list args, int *chars);
void	print_poux(t_tags *tags, va_list args, int *chars);
void	print_f(t_tags *tags, va_list args, int *chars);
char	*ft_itoa_without_sign(intmax_t n);
int		ft_atoi(char const *str);
char	*ft_itoa_base(uintmax_t ln, unsigned int base);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(char const *s1);
size_t	ft_strlen(char const *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnew(size_t size);
char	*ft_strcpy(char *dst, const char *src);
int		ft_isdigit(int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strncpy(char *dst, const char *src, size_t len);
int		ft_tolower(int c);
void	ft_str_toupper(char	*str);

#endif