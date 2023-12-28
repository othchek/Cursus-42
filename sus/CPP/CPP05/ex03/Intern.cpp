#include "Intern.hpp"

Intern::Intern(void) {
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(Intern const &copy) {
	std::cout << "Intern Copy assignment operator called" << std::endl;
	*this = copy;
}

Intern::~Intern(void) {
	std::cout << "Intern destructor called" << std::endl;
}

Intern const	&Intern::operator = (Intern const &rhs) {
	std::cout << "Intern Copy assignment operator called" << std::endl;
	if (this == &rhs) {
        return *this;
    }
	return (*this);
}

AForm *Intern::makeForm(std::string FormName, std::string FormTarget) {
	std::cout << BLUE << "makeForm function called" << RESET << std::endl;
	std::string array[3] = {"robotomy request", "shruberry request", "presidential request"};
	for (int index = 0; index < 3; index++) {
		if (FormName == array[index]) {
			switch (index) {
				case 0:
					return (new RobotomyRequestForm(FormTarget));
					break;
				case 1:
					return (new ShrubberyCreationForm(FormTarget));
					break;
				case 2:
					return (new PresidentialPardonForm(FormTarget));
					break;
				default:
					std::cout << "Something wrong in either FormName or FormTarget" << std::endl;
			}
		}
	}
	return (NULL);
}