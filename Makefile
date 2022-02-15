# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nsamoilo <nsamoilo@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/08 14:28:06 by nsamoilo          #+#    #+#              #
#    Updated: 2022/02/15 10:23:15 by nsamoilo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT_FUNCTIONS = ft_itoa_base ft_atoi ft_itoa_without_sign \
			ft_putchar ft_putstr ft_strcmp ft_strncmp ft_strdup ft_strlen ft_strnew \
			ft_isdigit ft_strcpy ft_memset ft_strjoin ft_strsub ft_strncpy \
			ft_tolower ft_str_toupper
FT_PRINTF_FUNCTIONS = ft_printf parse_flags parse_length parse_precision parse_width \
			print_specifier print_left_or_right print_cs  \
			print_di print_poux print_f helpers
LIBFT_FILES = $(patsubst %, libft/%.c, $(LIBFT_FUNCTIONS))
LIBFT_OBJECTS = $(patsubst %, %.o, $(LIBFT_FUNCTIONS))
FT_PRINTF_FILES = $(patsubst %, %.c, $(FT_PRINTF_FUNCTIONS))
FT_PRINTF_OBJECTS = $(patsubst %, %.o, $(FT_PRINTF_FUNCTIONS))

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(FT_PRINTF_FILES)
	@gcc -Wall -Wextra -Werror -c $(LIBFT_FILES)
	@ar rc $(NAME) $(FT_PRINTF_OBJECTS) $(LIBFT_OBJECTS)
	@ranlib $(NAME)

clean:
	@rm -f $(FT_PRINTF_OBJECTS) $(LIBFT_OBJECTS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

test:
	@make -C eval_tests/ test

gcc:
	@make -C eval_tests/ gcc
	
val:
	@make -C eval_tests/ val