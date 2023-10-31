NAME = Fixed

CFLAGS = -Wall -Wextra -Werror -std=c++98

INC = Fixed.hpp

CPP = c++

SRC = main.cpp Fixed.cpp

all : $(NAME)

$(NAME) : $(SRC) $(INC)
	$(CPP) $(CFLAGS) $(SRC) -o $(NAME)

fclean :
	rm -rf $(NAME)

re : clean all

.PHONY : clean fclean re