# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 14:36:47 by mbachar           #+#    #+#              #
#    Updated: 2023/04/29 13:10:39 by otchekai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = push_swap_bonus

CFLAGS = -Wall -Wextra -Werror

INC = push_swap.h

CC = cc

LIBFT = ./libft/libft.a

SRC = push_swap.c parsing.c the_all_you_need.c instructions.c instructions2.c instructions3.c \
	three_random_numbers.c four_five_random_numbers.c bzaf_random_numbers.c

SRC_B = ./bonus/push_swap_bonus.c parsing.c the_all_you_need.c instructions.c instructions2.c instructions3.c \
	three_random_numbers.c four_five_random_numbers.c bzaf_random_numbers.c get_next_line.c get_next_line_utils.c

OBJ	= $(SRC:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

all: $(NAME)

bonus: $(BONUS)

%.o : %.c $(INC)
	@ $(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@ cd ./libft && make
	@ $(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(BONUS): $(OBJ_B)
	@ cd ./libft && make
	@ $(CC) $(CFLAGS) $(OBJ_B) -o $(BONUS) $(LIBFT)

clean:
	@ rm -rf $(OBJ)
	@ cd ./libft && make clean

fclean:
	@ rm -rf $(NAME) $(OBJ)
	@ cd ./libft && make fclean

re: fclean all

.PHONY: fclean clean re bonus