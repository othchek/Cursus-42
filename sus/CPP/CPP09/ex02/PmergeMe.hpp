#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
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
		int d_struggler;
		int flag;
		std::vector<int> vec;
		std::vector<int> mainchain;
		std::vector<int> jacobsthal;
		std::vector<int> combination;
		std::vector<int> pend;
		std::vector<std::pair<int, int> > pairs;
		//-----------------------------------------//
		std::deque<int> d_vec;
		std::deque<int> d_mainchain;
		std::deque<int> d_jacobsthal;
		std::deque<int> d_combination;
		std::deque<int> d_pend;
		std::deque<std::pair<int, int> > d_pairs;
	public :
		PmergeMe(void);
		PmergeMe(PmergeMe const &copy);
		~PmergeMe(void);
		PmergeMe const &operator = (PmergeMe const &rhs);
		int		f_stoi(std::string numb);
		void	store_numbers(std::string str, int size);
		void	makePairs();
		void	SortMainChain();
		void	SeperatePairs();
		void	Generatejacobsthal();
		int		binarySearch(std::vector<int> vec, int x);
		//----------------------------------------------------->>//
		void	d_store_numbers(std::string str, int size);
		void	d_makePairs();
		void	d_SortMainChain();
		void	d_SeperatePairs();
		void	d_Generatejacobsthal();
		int		d_binarySearch(std::deque<int> d_vec, int x);
};

#endif