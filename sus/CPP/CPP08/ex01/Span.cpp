#include "Span.hpp"

Span::Span(void) {
	N = 0;
	vec.reserve(0);
}

Span::Span(unsigned int N) {
	vec.reserve(N);
	this->N = N;
}

Span::Span(Span const &copy) {
	*this = copy;
}

Span::~Span(void) {}

Span const	&Span::operator = (Span const &rhs) {
	if (this == &rhs) {
        this->vec = rhs.vec;
		this->N = rhs.N;
    }
	return (*this);
}

void Span::addNumber(int i) {
	if (vec.size() >= N)
		throw(sub());
	vec.push_back(i);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (vec.size() + std::distance(begin, end) > N) {
		throw (sub());
	}
	vec.insert(vec.end(), begin, end);
}

int	Span::longestSpan() {
	if (vec.empty())
		throw (sub());
	std::sort(vec.begin(), vec.end());
	int longest = vec.back() - vec.front();
	return (longest);
}

int	Span::shortestSpan() {
	if (vec.empty())
		throw (sub());
	std::sort(vec.begin(), vec.end());
	int shortest = INT_MAX;
	for (size_t k = 0; k != vec.size() - 1; k++) {
		if (vec[k + 1] - vec[k] < shortest)
			shortest = vec[k + 1] - vec[k];
	}
	return (shortest);
}