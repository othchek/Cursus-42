NAME = Base

CFLAGS = -Wall -Wextra -Werror -std=c++98

INC = Base.hpp A.hpp B.hpp C.hpp

CPP = c++

SRC = main.cpp Base.cpp

all : $(NAME)

$(NAME) : $(SRC) $(INC)
	$(CPP) $(CFLAGS) $(SRC) -o $(NAME)

fclean :
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean re