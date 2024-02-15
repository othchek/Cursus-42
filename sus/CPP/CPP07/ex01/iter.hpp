#ifndef ITER_HPP
# define ITER_HPP
#include <iostream>

template <typename T, typename funct>
void	iter(const T *array, int length, funct function) {
	for (int i = 0; i < length; i++)
		function(array[i]);
}

template <typename T>
void	func(const T &a) {
	std::cout << "This " << a << " is very clumsy in a sense" << std::endl;
}
#endif