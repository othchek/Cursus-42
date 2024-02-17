#ifndef SPAN_HPP
# define SPAN_HPP
#include <iostream>
#include <vector>

class Span
{
	private :
		std::vector <int> vec;
		unsigned int N;
	public :
		Span(void);
		Span(unsigned int N);
		Span(Span const &copy);
		class sub : public std::exception {
			public :
				const char *what() const throw() {
					return ("Error Out of Bounds");
				}
		};
		~Span(void);
		Span const &operator = (Span const &rhs);
		void addNumber(int i);
		void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();
};

#endif