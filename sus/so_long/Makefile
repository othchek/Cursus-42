# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 16:38:26 by otchekai          #+#    #+#              #
#    Updated: 2023/11/17 22:51:13 by otchekai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror 
INC = so_long.h get_next_line.h
SRC = 	so_long.c get_next_line.c get_next_line_utils.c read_map.c ft_error.c map_parsing.c Backtracking.c harkti_playar.c \
		destroymap.c printmove.c so_long_utils.c

OBJ = $(SRC:.c=.o)
 
all : $(NAME)

$(NAME) : $(OBJ) $(INC)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY: re clean fclean