NAME = Harl

CFLAGS = -Wall -Wextra -Werror

CPP = c++

INC = Harl.hpp

SRC = main.cpp Harl.cpp

all : $(NAME)

$(NAME) : $(SRC) $(INC)
	$(CPP) $(CFLAGS) $(SRC) -o $(NAME)

clean : 
	rm -rf $(NAME)

re : clean all

.PHONY : clean fclean re
