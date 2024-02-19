#include "RPN.hpp"

int main(int ac, char **av) 
{
	try {
		if (ac < 2)
		{
			std::cout << "Invalid argument" << std::endl;
			exit (1);
		}
		RPN obj;
		obj.push(av[1]);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}