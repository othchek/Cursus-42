NAME = Serialization

CFLAGS = -Wall -Wextra -Werror -std=c++98

INC = Serializer.hpp

CPP = c++

SRC = main.cpp Serializer.cpp

all : $(NAME)

$(NAME) : $(SRC) $(INC)
	$(CPP) $(CFLAGS) $(SRC) -o $(NAME)

fclean :
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean re