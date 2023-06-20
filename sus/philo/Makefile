# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/06 11:56:37 by otchekai          #+#    #+#              #
#    Updated: 2023/06/20 16:46:24 by otchekai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CFLAGS = -Wall -Wextra -Werror -g -fsanitize=thread

SRC = philo.c the_all_you_need.c philo_utils.c

OBJ = $(SRC:.c=.o)

INC = philo.h

all : $(NAME)

%.o : %.c $(INC)
	@ $(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@ $(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean :
	@ rm -rf $(OBJ)

fclean : clean
	@ rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean re bonus