NAME = Bureaucrat

CFLAGS = -Wall -Wextra -Werror -std=c++98

INC = Bureaucrat.hpp

CPP = c++

SRC = main.cpp Bureaucrat.cpp

all : $(NAME)

$(NAME) : $(SRC) $(INC)
	$(CPP) $(CFLAGS) $(SRC) -o $(NAME)

fclean :
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean re