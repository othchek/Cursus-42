NAME = convert

CFLAGS = #-Wall -Wextra -Werror -std=c++98

INC = ScalarConverter.hpp

CPP = c++

SRC = main.cpp ScalarConverter.cpp

all : $(NAME)

$(NAME) : $(SRC) $(INC)
	$(CPP) $(CFLAGS) $(SRC) -o $(NAME)

fclean :
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean re