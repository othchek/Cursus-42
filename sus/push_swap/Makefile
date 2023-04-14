# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 14:36:47 by mbachar           #+#    #+#              #
#    Updated: 2023/04/12 16:43:23 by otchekai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

INC = push_swap.h

CC = cc

LIBFT = ./libft/libft.a

SRC = push_swap.c parsing.c the_all_you_need.c instructions.c instructions2.c instructions3.c

OBJ	= $(SRC:.c=.o)

all: $(NAME)

%.o : %.c $(INC)
	@ $(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@ cd ./libft && make
	@ $(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)

clean:
	@ rm -rf $(OBJ)
	@ cd ./libft && make clean

fclean:
	@ rm -rf $(NAME) $(OBJ)
	@ cd ./libft && make fclean

re: fclean all

.PHONY: fclean clean re bonus