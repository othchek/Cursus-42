NAME = megaphone

CFLAGS = -Wall -Wextra -Werror

CPP = c++

SRC = megaphone.cpp

all : $(NAME)

$(NAME) : $(SRC)
	$(CPP) $(CFLAGS) $(SRC) -o $(NAME)

clean : 
	rm -rf $(NAME)

re : clean all