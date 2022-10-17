# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 10:09:01 by otchekai          #+#    #+#              #
#    Updated: 2022/10/17 15:19:11 by otchekai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
NAME = libft.a
SRC = ft_atoi.c \
        ft_isalnum.c \
        ft_isalpha.c \
        ft_isascii.c \
        ft_isdigit.c \
        ft_isprint.c \
        ft_strchr.c \
        ft_strlen.c \
        ft_strncmp.c \
        ft_strrchr.c \
        ft_tolower.c \
        ft_toupper.c \
        ft_bzero.c \
        ft_strnstr.c \
        ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_memchr.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) r $(NAME) $(OBJ)

%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean :
	rm -fr $(OBJ)

fclean : 
	rm -fr $(NAME)

re :
	rm -fr $(NAME) $(OBJ)