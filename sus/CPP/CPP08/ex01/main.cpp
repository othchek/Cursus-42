#include "Span.hpp"

int main()
{
	try {
		// std::vector<int> vector;

		// for (int i = 0; i < 10000; i++)
		// 	vector.push_back(i);
		Span sp(10);
		sp.addNumber(1);
		// sp.addNumbers(vector.begin(), vector.end());
		// sp.addNumber(3);
		// sp.addNumber(9);
		// sp.addNumber(45);
		// sp.addNumber(69);
		// sp.addNumber(1);
		std::cout << "Shortest Span is " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span is " << sp.longestSpan() << std::endl;
		return 0;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}