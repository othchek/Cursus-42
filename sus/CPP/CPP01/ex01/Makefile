NAME = horde

CFLAGS = -Wall -Wextra -Werror

INC = Zombie.hpp

CPP = c++

SRC = main.cpp Zombie.cpp zombieHorde.cpp

all : $(NAME)

$(NAME) : $(SRC) $(INC)
	$(CPP) $(CFLAGS) $(SRC) -o $(NAME)

clean : 
	rm -rf $(NAME)

fclean : clean

re : clean all

.PHONY : clean fclean re