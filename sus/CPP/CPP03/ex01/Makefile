NAME = scavtrap

CFLAGS = -Wall -Wextra -Werror -std=c++98

INC = ScavTrap.hpp

CPP = c++

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp

all : $(NAME)

$(NAME) : $(SRC) $(INC)
	$(CPP) $(CFLAGS) $(SRC) -o $(NAME)

clean :
	rm -rf $(NAME)

fclean : clean

re : clean all

.PHONY : clean fclean re