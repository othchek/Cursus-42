NAME = violence

CFLAGS = -Wall -Wextra -Werror

INC = HumanA.hpp HumanB.hpp Weapon.hpp

CPP = c++

SRC = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

all : $(NAME)

$(NAME) : $(SRC) $(INC)
	$(CPP) $(CFLAGS) $(SRC) -o $(NAME)

clean : 
	rm -rf $(NAME)

fclean : clean

re : clean all

.PHONY : clean fclean re