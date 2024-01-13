SRCS =  main.cpp \
		./src/server/servsocket.cpp\
		./src/commands/channel_parse.cpp\
		
FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = ircserv
OBJ =  $(SRCS:.cpp=.o)

%.o : %.cpp ./inc/servsocket.hpp ./inc/channel.hpp
	@c++ $(FLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	@c++ $(FLAGS) $(OBJ) -o $@

all : $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all