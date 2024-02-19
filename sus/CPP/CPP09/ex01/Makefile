NAME = RPN

CFLAGS = -Wall -Wextra -Werror -std=c++98

INC = RPN.hpp

CPP = c++

SRC = main.cpp RPN.cpp

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(SRC) $(INC) $(OBJ)
	$(CPP) $(CFLAGS) $(SRC) -o $(NAME)

fclean :
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean re