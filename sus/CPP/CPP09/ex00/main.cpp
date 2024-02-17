#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac < 2) {
		std::cerr << "Invalid argument" << std::endl;
		exit (1);
	}
	BitcoinExchange obj;
	obj.read_file();
	obj.read_input(av[1]);
}