#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {
	std::cout << "Bureaucrat Default constructor called" << std::endl;
	Name = "abmoula";
	Grade = 50;
}

Bureaucrat::Bureaucrat(std::string Name_, int Grade_) : Name(Name_), Grade(Grade_) {
	std::cout << "Bureaucrat parameterized Name constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) {
	*this = copy;
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat Destructor called" << std::endl;
}

Bureaucrat const	&Bureaucrat::operator = (Bureaucrat const &obj) {
	if (this == &obj) {
        return *this;
    }
    return (*this);
}

std::string	Bureaucrat::getName(void) const {
	return (Name);
}

int			Bureaucrat::getGrade(void) const {
	return (Grade);
}

std::ostream &operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName() << "'s grade : " << obj.getGrade();
    return os;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade Too High");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade Too Low");
}

void	Bureaucrat::increment_grade() {
	if (Grade <= 1)
		throw GradeTooHighException();
	Grade--;
}

void	Bureaucrat::decrement_grade() {
	if (Grade >= 150)
		throw GradeTooLowException();
	Grade++;
}