# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 14:36:47 by mbachar           #+#    #+#              #
#    Updated: 2023/03/31 14:43:12 by otchekai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP 	= 	push_swap

CFLAGS		=	-Wall -Wextra -Werror

INC 		= 	push_swap.h

CC			=	cc

LIBFT		=	./libft/libft.a

MAN_SRC 	= 	push_swap.c \
				parsing.c

MAN_OBJ		=	$(MAN_SRC:.c=.o)

#CHECKER	= 	checker

#BON_SRC 	= 	checker.c

all: $(PUSH_SWAP) #$(CHECKER)

%.o : %.c $(INC)
	@ $(CC) $(CFLAGS) -c $< -o $@

$(PUSH_SWAP): $(MAN_OBJ)
	@ cd ./libft && make
	@ $(CC) $(CFLAGS) $(MAN_OBJ) -o $(PUSH_SWAP) $(LIBFT)

clean:
	@ rm -fr $(MAN_OBJ)
	@ cd ./libft && make clean

fclean:
	@ rm -fr $(PUSH_SWAP) $(MAN_OBJ)
	@ cd ./libft && make fclean

re: fclean all

.PHONY: fclean clean re bonus