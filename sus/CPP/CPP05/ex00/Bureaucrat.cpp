#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {
	std::cout << "Bureaucrat Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) {
	*this = copy;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat const	&Bureaucrat::operator = (Bureaucrat const &rhs) {
	return (*this);
}

void	 Bureaucrat::GradeTooHighException() {

}

void	 Bureaucrat::GradeTooLowException() {

}

void	Bureaucrat::getName(void) {

}

void	Bureaucrat::getGrade(void) {

}

void	increment_grade(int grade) {

}

void	decrement_grade(int grade) {

}

std::ostream &operator<<(std::ostream& os, const Fixed& obj)
{
    os << obj.toFloat();
    return os;
}