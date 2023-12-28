#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

int main() {
	try {
		Bureaucrat obj("sma3in", 2);
		Intern someRandomIntern;
		AForm* rrf;
		rrf = someRandomIntern.makeForm("shruberry request", "Bender");
		if (rrf)
			rrf->execute(obj);
		delete rrf;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}