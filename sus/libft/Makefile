# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/12 10:09:01 by otchekai          #+#    #+#              #
#    Updated: 2022/10/28 08:49:10 by otchekai         ###   ########.fr        #
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
		ft_memchr.c \
		ft_memcmp.c \
        ft_calloc.c \
        ft_strdup.c \
        ft_strlcat.c \
        ft_strlcpy.c \
        ft_substr.c \
        ft_strtrim.c \
        ft_strjoin.c \
        ft_strmapi.c \
        ft_putchar_fd.c \
        ft_putendl_fd.c \
        ft_putnbr_fd.c \
        ft_putstr_fd.c \
        ft_striteri.c \
        ft_itoa.c \
        # ft_split.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) r $(NAME) $(OBJ)

%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) 
	rm -f $(OBJ)

re: fclean all

.PHONY: all bonus clean fclean re