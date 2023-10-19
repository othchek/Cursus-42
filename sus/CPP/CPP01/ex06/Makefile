NAME = harlFilter

CFLAGS = -Wall -Wextra -Werror

CPP = c++

INC = harl.hpp

SRC = main.cpp harl.cpp

all : $(NAME)

$(NAME) : $(SRC) $(INC)
	$(CPP) $(CFLAGS) $(SRC) -o $(NAME)

clean : 
	rm -rf $(NAME)

fclean : clean

re : clean all

.PHONY : clean fclean re
