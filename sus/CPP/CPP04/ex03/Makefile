NAME = AMateria

CFLAGS = -Wall -Wextra -Werror -std=c++98

INC = AMateria.hpp Character.hpp cure.hpp ice.hpp MateriaSource.hpp

CPP = c++

SRC = main.cpp AMateria.cpp Character.cpp cure.cpp ice.cpp MateriaSource.cpp

all : $(NAME)

$(NAME) : $(SRC) $(INC)
	$(CPP) $(CFLAGS) $(SRC) -o $(NAME)

fclean :
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean re