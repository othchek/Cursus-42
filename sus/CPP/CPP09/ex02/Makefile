NAME = PmergeMe

CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g 

INC = PmergeMe.hpp

CPP = c++

SRC = main.cpp PmergeMe.cpp

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(SRC) $(INC) $(OBJ)
	$(CPP) $(CFLAGS) $(SRC) -o $(NAME)

fclean :
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean re