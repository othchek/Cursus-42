NAME = Form

CFLAGS = -Wall -Wextra -Werror -std=c++98

INC = Bureaucrat.hpp Form.hpp

CPP = c++

SRC = main.cpp Bureaucrat.cpp Form.cpp

all : $(NAME)

$(NAME) : $(SRC) $(INC)
	$(CPP) $(CFLAGS) $(SRC) -o $(NAME)

fclean :
	rm -rf $(NAME)

fuck :
	rm -rf ../../.vscode

re : fclean all

.PHONY : clean fclean re