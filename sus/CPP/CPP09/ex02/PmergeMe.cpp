#include "PmergeMe.hpp"

int PmergeMe::f_stoi(std::string numb)
{
	int ret;

	for (int i = 0; (size_t)i < numb.length(); i++)
		if (!std::isdigit(numb[i]))
			throw std::invalid_argument("Error");
	std::stringstream var(numb);
	if (!(var >> ret))
		throw std::invalid_argument("Error");
	return ret;
}

PmergeMe::PmergeMe(void) {
	struggler = 0;
}

PmergeMe::PmergeMe(PmergeMe const &copy)
{
	*this = copy;
}

PmergeMe::~PmergeMe(void) {
}

PmergeMe const &PmergeMe::operator=(PmergeMe const &rhs)
{
	if (this == &rhs)
	{
		this->combination = rhs.combination;
		this->vec = rhs.vec;
		this->pairs = rhs.pairs;
		this->pend = rhs.pend;
		this->mainchain = rhs.mainchain;
		this->jacobsthal = rhs.jacobsthal;
		return *this;
	}
	return (*this);
}

void PmergeMe::store_numbers(std::string str, int size)
{
	int number = f_stoi(str);
	vec.push_back(number);
	if (vec.size() == (size_t)size - 1 && vec.size() % 2 == 1)
	{
		struggler = vec.back();
		vec.pop_back();
		flag = true;
	}
}

void PmergeMe::makePairs()
{
	std::cout << "Before :";
	for (int i = 0; i < (int)vec.size(); i++)
		std::cout << " " << vec[i];
	std::cout << std::endl;
	for (int i = 0; (size_t)i + 1 < vec.size(); i += 2)
		pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
	for (int i = 0; (size_t)i < pairs.size(); i++)
	{
		if (pairs[i].first < pairs[i].second)
			std::swap(pairs[i].first, pairs[i].second);
	}
}

void PmergeMe::SortMainChain()
{
	std::vector<std::pair<int, int> >::iterator fir = pairs.begin();
	std::vector<std::pair<int, int> >::iterator las = pairs.end();
	std::sort(fir, las);
	SeperatePairs();
}

void PmergeMe::SeperatePairs()
{
	for (int i = 0; (size_t)i < pairs.size(); i++)
	{
		if (mainchain.empty())
			mainchain.push_back(pairs[i].second);
		mainchain.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}
}

void PmergeMe::Generatejacobsthal()
{
	jacobsthal.push_back(0);
	jacobsthal.push_back(1);
	for (int i = 0; i < 15; i++)
		jacobsthal.push_back(jacobsthal[i] * 2 + jacobsthal[i + 1]);
	for (int j = 3; j < 15; j++) {
		int result = jacobsthal[j];
		combination.push_back(result);
		result--;
		for (int i = 0; (size_t)i < jacobsthal.size(); i++) {
			if (result != jacobsthal[i] && (size_t)i + 1 == jacobsthal.size()) {
				combination.push_back(result);
				result--;
				i = 0;
			}
			else if (result == jacobsthal[i])
				break ;
		}
	}
	for (int i = 0; i < (int)pend.size(); i++) {
		if (combination[i] - 1 < (int)pend.size()) {
			std::vector<int>::iterator it = std::lower_bound(mainchain.begin(), mainchain.end(), pend[combination[i] - 1]);
			if (it != mainchain.end())
				mainchain.insert(it, pend[combination[i] - 1]);
		}
	}
	if (vec.size() % 2 == 1) {
		std::vector<int>::iterator it = std::lower_bound(mainchain.begin(), mainchain.end(), struggler);
		if (it != mainchain.end())
			mainchain.insert(it, struggler);
	}
	std::cout << "After :";
	for (int i = 0; i < (int)mainchain.size(); i++)
		std::cout << " " << mainchain[i];
	std::cout << std::endl;
}
