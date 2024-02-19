#include "PmergeMe.hpp"

int PmergeMe::f_stoi(std::string numb)
{
	int ret;

	for (int i = 0; (size_t)i < numb.length(); i++)
		if (!std::isdigit(numb[i]))
			throw std::invalid_argument("Error: Not Number\n");
	std::stringstream var(numb);
	if (!(var >> ret))
		throw std::invalid_argument("Error: Overflow\n");
	return ret;
}

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(PmergeMe const &copy) {
	*this = copy;
}

PmergeMe::~PmergeMe(void) {
	struggler = 0;
}

PmergeMe const	&PmergeMe::operator = (PmergeMe const &rhs)
{
	if (this == &rhs) {
        return *this;
    }
	return (*this);
}

void	PmergeMe::store_numbers(std::string str, int size) {
	int number = f_stoi(str);
	vec.push_back(number);
	if (vec.size() == (size_t)size - 1 && vec.size() % 2 == 1) {
		struggler = vec.back();
		vec.pop_back();
	}
}

void PmergeMe::makePairs() {
	for (int i = 0; (size_t)i + 1 < vec.size(); i += 2)
		pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
	for (int i = 0; (size_t)i < pairs.size(); i++) {
		if (pairs[i].first < pairs[i].second)
			std::swap(pairs[i].first, pairs[i].second);
	}
}

void PmergeMe::SortMainChain() {
	std::vector<std::pair <int, int> >::iterator fir = pairs.begin();
	std::vector<std::pair<int, int> >::iterator las = pairs.end();
	std::sort(fir, las);
	// for (int i = 0; (size_t)i < pairs.size(); i += 1) {
		// std::cout << "First " << pairs[i].first << std::endl;
		// std::cout << "Second " << pairs[i].second << std::endl;
	// }
	SeperatePairs();
}

void PmergeMe::SeperatePairs() {
	for (int i = 0; (size_t)i < pairs.size(); i++) {
		if (mainchain.empty())
			mainchain.push_back(pairs[i].second);
		mainchain.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}
	for (int i = 0; (size_t)i < mainchain.size(); i++) {
		std::cout << "mainchain " << mainchain[i] << std::endl;
	}
	for (int i = 0; (size_t)i < pend.size(); i++) {
		std::cout << "Pend " << pend[i] << std::endl;
	}
}