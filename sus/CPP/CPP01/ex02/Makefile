NAME = main

CFLAGS = -Wall -Wextra -Werror

CPP = c++

SRC = main.cpp

all : $(NAME)

$(NAME) : $(SRC) $(INC)
	$(CPP) $(CFLAGS) $(SRC) -o $(NAME)

clean : 
	rm -rf $(NAME)

fclean : clean

re : clean all

.PHONY : clean fclean re