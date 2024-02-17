#include "easyfind.hpp"

int main() {
	std::vector<int> vec;
	for (int i = 0; i < 5; i++) {
		vec.push_back(i);
	}
	easyfind(vec, 5);
}