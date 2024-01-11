NAME = ircserv

CFLAGS = -Wall -Wextra -Werror

INC = ./inc/channel.hpp ./inc/irc_server.hpp

CPP = c++

SRC = ./src/commands/channel_parse.cpp main.cpp ./src/server/irc_server.cpp

all : $(NAME)

$(NAME) : $(SRC) $(INC)
	$(CPP) $(CFLAGS) $(SRC) -o $(NAME)

clean : 
	rm -rf $(NAME)

fuck :
	rm -rf .vscode

re : clean all

.PHONY : clean fclean re