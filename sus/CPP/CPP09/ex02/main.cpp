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
		std::cout << "Before :";
		for (int i = 1; av[i]; i++) {
			obj.store_numbers(av[i], ac);
			std::cout << " " << av[i];
		}
		std::cout << std::endl;
		obj.makePairs();
		obj.SortMainChain();
		start = std::clock();
		obj.Generatejacobsthal();
		stop = std::clock();
		duration = (stop - start);
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::[..] : " << duration << " us" << std::endl;
		//---------------------------------------------------------------------------------------------------------------------->>//
		std::clock_t d_start;
		std::clock_t d_stop;
		double d_duration;
		obj.d_makePairs();
		obj.d_SortMainChain();
		d_start = std::clock();
		obj.d_Generatejacobsthal();
		d_stop = std::clock();
		d_duration = (d_stop - d_start);
		std::cout << "Time to process a range of " << ac - 1 << " elements with std::[..] : " << d_duration << " us" << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}