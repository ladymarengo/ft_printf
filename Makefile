# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 14:28:06 by nsamoilo          #+#    #+#              #
#    Updated: 2022/01/27 12:51:15 by nsamoilo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT_FUNCTIONS = ft_putchar ft_putchar_fd ft_putstr ft_putstr_fd ft_putendl \
			ft_putendl_fd ft_itoa ft_putnbr ft_putnbr_fd ft_strnew ft_strdel \
			ft_strclr ft_striter ft_striteri ft_strlen ft_strmap ft_strmapi \
			ft_strequ ft_strnequ ft_isalpha ft_isdigit ft_isalnum ft_isascii \
			ft_isprint ft_toupper ft_tolower ft_atoi ft_strdup ft_strcpy \
			ft_strncpy ft_strcat ft_strncat ft_strlcat ft_strchr ft_strrchr \
			ft_strcmp ft_strncmp ft_strstr ft_strnstr ft_memset ft_memalloc \
			ft_memdel ft_bzero ft_memcpy ft_memccpy ft_memmove ft_memchr \
			ft_memcmp ft_strsub ft_strjoin ft_strtrim ft_strsplit \
			ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter \
			ft_lstmap ft_lstprint ft_strisx ft_calloc ft_lstaddend ft_strrev
FT_PRINTF_FUNCTIONS = ft_printf parse_flags parse_length parse_precision parse_width \
			print_specifier print_left_or_right print_csp ft_itoa_base ft_atoi ft_itoa_without_sign \
			ft_putchar ft_putstr ft_strcmp ft_strncmp ft_strdup ft_strlen ft_strnew \
			print_di ft_isdigit ft_strcpy ft_memset ft_strjoin ft_strsub ft_strncpy \
			ft_tolower ft_str_toupper print_oux
LIBFT_FILES = $(patsubst %, libft/%.c, $(LIBFT_FUNCTIONS))
LIBFT_OBJECTS = $(patsubst %, %.o, $(LIBFT_FUNCTIONS))
FT_PRINTF_FILES = $(patsubst %, %.c, $(FT_PRINTF_FUNCTIONS))
FT_PRINTF_OBJECTS = $(patsubst %, %.o, $(FT_PRINTF_FUNCTIONS))

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(FT_PRINTF_FILES)
	@ar rc $(NAME) $(FT_PRINTF_OBJECTS)
	@ranlib $(NAME)

clean:
	@rm -f $(FT_PRINTF_OBJECTS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

test: re
	@gcc main.c libftprintf.a
	@./a.out
	@rm a.out
	@make fclean
	
val: re
	@gcc main.c libftprintf.a
	@valgrind --leak-check=yes ./a.out
	@rm a.out
	@make fclean