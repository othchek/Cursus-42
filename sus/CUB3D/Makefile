# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/08 14:35:14 by otchekai          #+#    #+#              #
#    Updated: 2023/11/16 15:20:48 by otchekai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address

INC = cub3d.h get_next_line.h

SRC = cub3d.c cub3d_utils.c readmap.c get_next_line_utils.c get_next_line.c parsing.c ft_error.c parsing2.c readmap2.c cub3d_utils2.c \
	parsing3.c

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