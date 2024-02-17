NAME = btc

CFLAGS = -Wall -Wextra -Werror -std=c++98

INC = BitcoinExchange.hpp

CPP = c++

SRC = main.cpp BitcoinExchange.cpp

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(SRC) $(INC) $(OBJ)
	$(CPP) $(CFLAGS) $(SRC) -o $(NAME)

fclean :
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean re