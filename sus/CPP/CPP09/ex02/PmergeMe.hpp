#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <iostream>
#include <exception>
#include <sstream>

class PmergeMe
{
	private :
		int struggler;
		std::vector<int> vec;
		std::vector<int> mainchain;
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
};

#endif