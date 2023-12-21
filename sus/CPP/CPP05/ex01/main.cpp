#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat obj("abmoula", 150);
		std::cout << obj << std::endl;
		obj.decrement_grade();
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}