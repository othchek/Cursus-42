# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 16:38:26 by otchekai          #+#    #+#              #
#    Updated: 2023/02/09 22:55:13 by otchekai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
MAKEFLAGS = -s

CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRC = so_long.c get_next_line.c get_next_line_utils.c read_map.c ft_error.c map_parsing.c Backtracking.c 7arkti_playar_al3ayl.c
OBJ = $(SRC:.c=.o)

all : $(NAME)


$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME) libft.a

%.o : %.c 
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

.PHONY: re clean fclean