NAME = Harl

CFLAGS = -Wall -Wextra -Werror -std=c++98

CPP = c++

INC = harl.hpp

SRC = main.cpp harl.cpp

all : $(NAME)

$(NAME) : $(SRC) $(INC)
	$(CPP) $(CFLAGS) $(SRC) -o $(NAME)

clean : 
	rm -rf $(NAME)

fclean : clean

re : clean all

.PHONY : clean fclean re
