#include "Bureaucrat.hpp"
#include "Form.hpp"
int main() {
	Bureaucrat	person("abmoula", 15);
	Form		person1("sma3in", true, 14, 1);
	/*-----------Too High exception-----------*/
	try {
		person.set_grade(0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	/*-----------Too Low exception-----------*/
	try {
		person.set_grade(151);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	/*-----------couldn't sign-----------*/
	person.signForm(person1);
}