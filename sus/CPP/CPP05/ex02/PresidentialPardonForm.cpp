#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("abmoula", 25, 5) {
	std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
	target = "sma3iine";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target_) : AForm("abmoula", 25, 5) {
	std::cout << "PresidentialPardonForm parameterized constructor called" << std::endl;
	target = target_;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) {
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

PresidentialPardonForm const	&PresidentialPardonForm::operator = (PresidentialPardonForm const &rhs) {
	std::cout << "PresidentialPardonForm Copy assignment operator called" << std::endl;
	if (this == &rhs) {
        return *this;
    }
	return (*this);
}

void		PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!get_signed() && executor.getGrade() < get_sign_Grade())
		throw GradeTooLowException();
	std::cout << PURPLE << "I wish to inform Mr. " << target << " that he has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}