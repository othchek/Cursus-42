#include "AForm.hpp"

AForm::AForm(void) : Name("abmoula"), is_signed(false), sign(5), exec(5) {
	std::cout << "AForm default constructor called" << std::endl;
	if (sign > 150)
		throw GradeTooLowException();
	else if (sign < 1)
		throw GradeTooHighException();
}

AForm::AForm(std::string Name_, int sign_grade_, int exec_grade_) : Name(Name_), is_signed(false), sign(sign_grade_), exec(exec_grade_) {
	std::cout << "AForm parameterized constructor called" << std::endl;
	if (sign > 150)
		throw GradeTooLowException();
	else if (sign < 1)
		throw GradeTooHighException();
}

// AForm::AForm(AForm const &copy) {
	// std::cout << "AForm copy constructor called" << std::endl;
	// *this = copy;
// }

AForm::~AForm(void) {
	std::cout << "AForm destructor called" << std::endl;
}

AForm const	&AForm::operator = (AForm const &obj) {
	std::cout << "AForm Copy assignment operator called" << std::endl;
	if (this == &obj) {
        return *this;
    }
    return (*this);
}

std::ostream &operator<<(std::ostream& os, const AForm& obj) {
    os << "Bureaucrat " << obj.getName() << "'s grade : " << obj.get_sign_Grade();
    return os;
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return ("Grade Too High");
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return ("Grade Too Low");
}

const char* AForm::Checksign::what() const throw() {
	return ("Already signed my friend");
}

bool	AForm::get_signed() const {
	return (is_signed);
}

std::string AForm::getName() const {
	return (Name);
}

int	AForm::get_exec_Grade() const {
	return (exec);
}

int	AForm::get_sign_Grade() const {
	 return (sign);
}

void	AForm::beSigned(Bureaucrat &obj) {
	if (this->get_signed())
		throw Checksign();
	if (obj.getGrade() < this->get_sign_Grade())
		throw GradeTooHighException();
	else
		is_signed = true;
}