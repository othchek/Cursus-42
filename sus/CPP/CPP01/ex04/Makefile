NAME = sedforlosers

CFLAGS = -Wall -Wextra -Werror

CPP = c++

INC = sed.hpp

SRC = main.cpp sed.cpp

all : $(NAME)

$(NAME) : $(SRC) $(INC)
	$(CPP) $(CFLAGS) $(SRC) -o $(NAME)

clean : 
	rm -rf $(NAME)

re : clean all

.PHONY : clean fclean re
