NAME = phoneBook

CFLAGS = -Wall -Wextra -Werror

INC = Contact.hpp PhoneBook.hpp \

CPP = c++

SRC = Contact.cpp PhoneBook.cpp main.cpp

all : $(NAME)

$(NAME) : $(SRC) $(INC)
	$(CPP) $(CFLAGS) $(SRC) -o $(NAME)

clean : 
	rm -rf $(NAME)

re : clean all

.PHONY : clean fclean re