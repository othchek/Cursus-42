#include "Bureaucrat.hpp"

int main()
{
	try {
		Bureaucrat obj;
		obj.decrement_grade();
		std::cout << obj << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}