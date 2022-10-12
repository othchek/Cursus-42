# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 10:09:01 by otchekai          #+#    #+#              #
#    Updated: 2022/10/12 11:16:56 by otchekai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libft.a

all : $(NAME)

$(NAME) : main.o ft_atoi.o ft_strrchr.o ft_strlen.o
	$(CC) -o $(NAME) main.o ft_atoi.o ft_strrchr.o ft_strlen.o -Wall -Wextra -Werror

main.o : main.c
	$(CC) -o main.o -c main.c -Wall -Wextra -Werror

ft_atoi.o : ft_atoi.c
	$(CC) -o ft_atoi.o -c ft_atoi.c -Wall -Wextra -Werror

ft_strrchr.o : ft_strrchr.c
	$(CC) -o ft_strrchr.o -c ft_strrchr.c -Wall -Wextra -Werror

ft_strlen.o : ft_strlen.c
	$(CC) -o ft_strlen.o -c ft_strlen.c -Wall -Wextra -Werror

clean : 
	rm -fr *.o

fclean : 
	rm -fr $(NAME)

re :
	rm -fr $(NAME) *.o