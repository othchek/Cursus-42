#include "Form.hpp"

Form::Form(void) : Name("abmoula"), is_signed(false), sign_grade(5), exec_grade(5) {
	std::cout << "Form default constructor called" << std::endl;
	if (sign_grade > 150)
		throw GradeTooLowException();
	else if (sign_grade < 1)
		throw GradeTooHighException();
}

Form::Form(std::string Name_, bool is_signed_, int sign_grade_, int exec_grade_) : Name(Name_), is_signed(is_signed_), sign_grade(sign_grade_), exec_grade(exec_grade_) {
	std::cout << "Form parameterized Name constructor called" << std::endl;
	if (sign_grade > 150)
		throw GradeTooLowException();
	else if (sign_grade < 1)
		throw GradeTooHighException();
}

Form::Form(Form const &copy) : sign_grade(copy.sign_grade), exec_grade(copy.exec_grade) {
	std::cout << "Form copy constructor called" << std::endl;
	*this = copy;
}

Form::~Form(void) {
	std::cout << "Form destructor called" << std::endl;
}

Form const	&Form::operator = (Form const &obj) {
	std::cout << "Form Copy assignment operator called" << std::endl;
	if (this == &obj) {
        return *this;
    }
    return (*this);
}

std::ostream &operator<<(std::ostream& os, const Form& obj) {
    os << "Form " << obj.getName() << "'s grade : " << obj.get_sign_Grade() << " Form's exec grade : " << obj.get_exec_Grade();
    return os;
}

const char*	Form::GradeTooHighException::what() const throw() {
	return ("Grade Too High");
}

const char*	Form::GradeTooLowException::what() const throw() {
	return ("Grade Too Low");
}

const char* Form::Checksign::what() const throw() {
	return ("Already signed my friend");
}

bool	Form::get_signed() {
	return (is_signed);
}

std::string Form::getName() const {
	return (Name);
}

int	Form::get_exec_Grade() const {
	return (exec_grade);
}

int	Form::get_sign_Grade() const {
	 return (sign_grade);
}

void	Form::beSigned(Bureaucrat &obj) {
	if (this->get_signed())
		throw Checksign();
	if (obj.getGrade() > this->get_sign_Grade())
		throw GradeTooLowException();
	else
		is_signed = true;
}