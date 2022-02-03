/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:02:21 by nsamoilo          #+#    #+#             */
/*   Updated: 2022/02/03 18:06:08 by nsamoilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdio.h>
# include <inttypes.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

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
