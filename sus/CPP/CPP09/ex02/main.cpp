#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	try {
		if (ac < 2)
		{
			std::cout << "Invalid argument" << std::endl;
			exit (1);
		}
		std::clock_t start;
		std::clock_t stop;
		double duration;
		PmergeMe obj;
		for (int i = 1; av[i]; i++)
			obj.store_numbers(av[i], ac);
		obj.makePairs();
		obj.SortMainChain();
		start = std::clock();
		obj.Generatejacobsthal();
		stop = std::clock();
		duration = (stop - start);
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::[..] : " << duration << " us" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}