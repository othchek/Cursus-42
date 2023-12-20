#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	public :
		Bureaucrat(void);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat(void);
		Bureaucrat const &operator = (Bureaucrat const &rhs);
		void GradeTooHighException();
		void GradeTooLowException();
		std::string getName(void);
		std::string getGrade(void);
		void	increment_grade(int grade);
		void	decrement_grade(int grade);
};
std::ostream &operator<<(std::ostream& os, const Bureaucrat& obj);

#endif