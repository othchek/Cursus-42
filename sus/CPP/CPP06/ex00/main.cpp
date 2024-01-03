#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Invalid arguments" << std::endl;
		exit (1);
	}
	ScalarConverter obj;
	obj.castfun(av[1]);
}