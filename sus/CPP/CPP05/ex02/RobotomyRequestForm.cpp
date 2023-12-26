#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("abmoula", 72, 45) {
	std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target_) : AForm("abmoula", 72, 45) {
	std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
	target = target_;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) {
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

RobotomyRequestForm const	&RobotomyRequestForm::operator = (RobotomyRequestForm const &rhs) {
	std::cout << "RobotomyRequestForm Copy assignment operator called" << std::endl;
	return (*this);
}

void		RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!get_signed() && executor.getGrade() > get_sign_Grade())
		throw GradeTooLowException();
	srand(time(0));
	int value = rand();
	std::cout << "HOORAY !!" << std::endl;
	if (value % 2 == 0)
		std::cout << ORANGE << target << " has successfully won the 50 50 gambit" << RESET << std::endl;
	else
		std::cout << RED << target << " has a lot to complain about" << RESET << std::endl;
}