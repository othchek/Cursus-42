#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		std::cerr << "Invalid arguments" << std::endl;
	ScalarConverter obj;
	obj.castfun(av[1]);
}