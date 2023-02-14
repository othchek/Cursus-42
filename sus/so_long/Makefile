# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 16:38:26 by otchekai          #+#    #+#              #
#    Updated: 2023/02/14 12:36:21 by otchekai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
# MAKEFLAGS = -s

CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRC = so_long.c get_next_line.c get_next_line_utils.c read_map.c ft_error.c map_parsing.c Backtracking.c 7arkti_playar.c \
	destroymap.c printmove.c
 OBJ = $(SRC:.c=.o)

all : $(NAME)


$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) libft.a

%.o : %.c  so_long.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

.PHONY: re clean fclean