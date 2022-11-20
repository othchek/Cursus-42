# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 10:57:40 by otchekai          #+#    #+#              #
#    Updated: 2022/11/20 20:53:09 by otchekai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
NAME = libftprintf.a
SRC =	ft_printf.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putnbr.c \
		ft_putnbrx.c \
		ft_putadd.c \
		ft_countlen.c \
		ft_print_unsigned.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) printf.h
	$(AR) -r $@ $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all