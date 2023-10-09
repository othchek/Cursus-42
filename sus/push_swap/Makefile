# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 14:36:47 by mbachar           #+#    #+#              #
#    Updated: 2023/05/05 15:55:19 by otchekai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

CFLAGS = -Wall -Wextra -Werror
INC = push_swap.h

CC = cc

LIBFT = ./libft/libft.a

SRC = push_swap.c parsing.c the_all_you_need.c instructions.c instructions2.c instructions3.c \
	three_random_numbers.c four_five_random_numbers.c bzaf_random_numbers.c yajoz_wa_ma_la_yajoz.c

SRC_B = ./bonus/push_swap_bonus.c parsing.c the_all_you_need.c instructions.c instructions2.c instructions3.c \
	three_random_numbers.c four_five_random_numbers.c bzaf_random_numbers.c get_next_line.c get_next_line_utils.c yajoz_wa_ma_la_yajoz.c \

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
	@ rm -rf $(OBJ) $(OBJ_B)
	@ cd ./libft && make clean

fclean:
	@ rm -rf $(NAME) $(BONUS) $(OBJ) $(OBJ_B)
	@ cd ./libft && make fclean

re: fclean all

.PHONY: fclean clean re bonus