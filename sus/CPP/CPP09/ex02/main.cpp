#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	try {
		if (ac < 2)
		{
			std::cout << "Invalid argument" << std::endl;
			exit (1);
		}
		PmergeMe obj;
		for (int i = 1; av[i]; i++)
			obj.store_numbers(av[i], ac);
		obj.makePairs();
		obj.SortMainChain();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}