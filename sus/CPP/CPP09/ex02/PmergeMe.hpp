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
	public :
		PmergeMe(void);
		PmergeMe(PmergeMe const &copy);
		~PmergeMe(void);
		PmergeMe const &operator = (PmergeMe const &rhs);
		void	store_numbers(std::string str);
		int		f_stoi(std::string numb);
		void	find_struggler();
		void	store_numbers(std::string str, int size);
};

#endif