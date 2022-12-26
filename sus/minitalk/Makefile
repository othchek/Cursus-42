# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otchekai <otchekai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 12:09:19 by otchekai          #+#    #+#              #
#    Updated: 2022/12/26 16:46:18 by otchekai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

SRC_C = client.c
SRC_S = server.c
LIBFT = ./libft/libft.a
LIBFT_DIR = ./libft


CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all : $(CLIENT) $(SERVER)

$(CLIENT): $(LIBFT)
	@ $(CC) $(CFLAGS) $(SRC_C) $(LIBFT) -o $(CLIENT)
	@printf "client ready.\n"

$(SERVER): $(LIBFT)
	@ $(CC) $(CFLAGS) $(SRC_C) $(LIBFT) -o $(SERVER)
	@printf "server ready.\n"


$(LIBFT):
	@$(MAKE) -C ./libft

clean:
	@ $(RM) $(CLIENT) $(SERVER)

fclean: clean
	@ $(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: clean re fclean 