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
	if (vec.size() == (size_t)size - 1 && vec.size() % 2 == 1)
		struggler = vec.back();
	std::cout << vec.back() << std::endl;
}

