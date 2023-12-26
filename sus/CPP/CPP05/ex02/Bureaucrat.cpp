#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : Name("abmoula"), Grade(1) {
	std::cout << "Bureaucrat Default constructor called" << std::endl;
	if (Grade < 1)
		throw GradeTooHighException();
	else if (Grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(std::string Name_, int Grade_) : Name(Name_), Grade(Grade_) {
	std::cout << "Bureaucrat parameterized Name constructor called" << std::endl;
	if (Grade < 1)
		throw GradeTooHighException();
	else if (Grade > 150)
		throw GradeTooLowException();
}

void	Bureaucrat::set_grade(int grade_) {
	if (grade_ <= 0) 
		throw(GradeTooHighException());
	else if (grade_ > 150)
		throw(GradeTooLowException());
	else
		Grade = grade_;
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
    os << "Bureaucrat " << obj.getName() << "'s grade : " << obj.getGrade();
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

void	Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
	}
	catch (std::exception) {
		std::cout << getName() << " could not execute Sadge!!" << std::endl;
	}
}
