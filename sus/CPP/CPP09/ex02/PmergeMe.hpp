#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <iostream>
#include <exception>
#include <sstream>
#include <ctime>

#define BLUE      "\x1b[34m"
#define ORANGE    "\x1b[33m"
#define RESET     "\x1b[0m"
#define PURPLE    "\x1b[96m"
#define GREEN     "\x1b[32m"
#define RED       "\x1b[1;31m"

class PmergeMe
{
	private :
		int struggler;
		std::vector<int> vec;
		std::vector<int> mainchain;
		std::vector<int> jacobsthal;
		std::vector<int> combination;
		std::vector<int> pend;
		std::vector<std::pair<int, int> > pairs;
	public :
		PmergeMe(void);
		PmergeMe(PmergeMe const &copy);
		~PmergeMe(void);
		PmergeMe const &operator = (PmergeMe const &rhs);
		void	store_numbers(std::string str);
		int		f_stoi(std::string numb);
		void	find_struggler();
		void	store_numbers(std::string str, int size);
		void	makePairs();
		void	mySwap();
		void	SortMainChain();
		void	SeperatePairs();
		void	Generatejacobsthal();
};

#endif