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
	flag = false;
}

PmergeMe::PmergeMe(PmergeMe const &copy)
{
	*this = copy;
}

PmergeMe::~PmergeMe(void) {
}

int PmergeMe::binarySearch(std::vector<int> vec, int x)
{
    int     left = 0, right = this->mainchain.size() - 1;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;
        if (vec[middle] == x)
            return (middle);
        if (vec[middle] < x)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return (left);
}

int PmergeMe::d_binarySearch(std::deque<int> d_vec, int x)
{
    int     left = 0, right = this->mainchain.size() - 1;

    while (left <= right)
    {
        int middle = left + (right - left) / 2;
        if (d_vec[middle] == x)
            return (middle);
        if (d_vec[middle] < x)
            left = middle + 1;
        else
            right = middle - 1;
    }
    return (left);
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
		this->d_combination = rhs.d_combination;
		this->d_vec = rhs.d_vec;
		this->d_pairs = rhs.d_pairs;
		this->d_pend = rhs.d_pend;
		this->d_mainchain = rhs.d_mainchain;
		this->d_jacobsthal = rhs.d_jacobsthal;
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
	if (flag) {
		int index = binarySearch(mainchain, struggler);
        mainchain.insert(index + mainchain.begin(), struggler);
	}
	std::cout << "After :";
	for (int i = 0; i < (int)mainchain.size(); i++)
		std::cout << " " << mainchain[i];
	std::cout << std::endl;
}

void PmergeMe::d_store_numbers(std::string str, int size)
{
	int number = f_stoi(str);
	d_vec.push_back(number);
	if (d_vec.size() == (size_t)size - 1 && d_vec.size() % 2 == 1)
	{
		d_struggler = d_vec.back();
		d_vec.pop_back();
		flag = true;
	}
}

void PmergeMe::d_makePairs()
{
	for (int i = 0; (size_t)i + 1 < d_vec.size(); i += 2)
		d_pairs.push_back(std::make_pair(d_vec[i], d_vec[i + 1]));
	for (int i = 0; (size_t)i < d_pairs.size(); i++)
	{
		if (d_pairs[i].first < d_pairs[i].second)
			std::swap(d_pairs[i].first, d_pairs[i].second);
	}
}

void PmergeMe::d_SortMainChain()
{
	std::deque<std::pair<int, int> >::iterator fir = d_pairs.begin();
	std::deque<std::pair<int, int> >::iterator las = d_pairs.end();
	std::sort(fir, las);
	d_SeperatePairs();
}

void PmergeMe::d_SeperatePairs()
{
	for (int i = 0; (size_t)i < d_pairs.size(); i++)
	{
		if (d_mainchain.empty())
			d_mainchain.push_back(d_pairs[i].second);
		d_mainchain.push_back(d_pairs[i].first);
		d_pend.push_back(d_pairs[i].second);
	}
}

void PmergeMe::d_Generatejacobsthal()
{
	d_jacobsthal.push_back(0);
	d_jacobsthal.push_back(1);
	for (int i = 0; i < 15; i++)
		d_jacobsthal.push_back(d_jacobsthal[i] * 2 + d_jacobsthal[i + 1]);
	for (int j = 3; j < 15; j++) {
		int result = d_jacobsthal[j];
		d_combination.push_back(result);
		result--;
		for (int i = 0; (size_t)i < d_jacobsthal.size(); i++) {
			if (result != d_jacobsthal[i] && (size_t)i + 1 == d_jacobsthal.size()) {
				d_combination.push_back(result);
				result--;
				i = 0;
			}
			else if (result == d_jacobsthal[i])
				break ;
		}
	}
	for (int i = 0; i < (int)d_pend.size(); i++) {
		if (d_combination[i] - 1 < (int)d_pend.size()) {
			std::deque<int>::iterator it = std::lower_bound(d_mainchain.begin(), d_mainchain.end(), d_pend[d_combination[i] - 1]);
			if (it != d_mainchain.end())
				d_mainchain.insert(it, d_pend[d_combination[i] - 1]);
		}
	}
	if (flag) {
		int index = d_binarySearch(d_mainchain, d_struggler);
        d_mainchain.insert(index + d_mainchain.begin(), d_struggler);
	}
}
