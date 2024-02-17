#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>

template <typename T>
void	easyfind(T a, int i) {
	typename T::iterator it = std::find(a.begin(), a.end(), i);
	if (it != a.end())
		std::cout << *it << std::endl;
	else
		std::cout << "Number not found!!" << std::endl;
}

#endif