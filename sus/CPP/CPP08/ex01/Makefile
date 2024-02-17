NAME = Span

CFLAGS = -Wall -Wextra -Werror -std=c++98

INC = Span.hpp

CPP = c++

SRC = main.cpp Span.cpp

all : $(NAME)

$(NAME) : $(SRC) $(INC)
	$(CPP) $(CFLAGS) $(SRC) -o $(NAME)

fclean :
	rm -rf $(NAME)

re : fclean all

.PHONY : clean fclean re