#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private :
		std::string const Name;
		int 		Grade;
	public :
		Bureaucrat(void);
		Bureaucrat(std::string Name_, int Grade_);
		Bureaucrat(Bureaucrat const &copy);
		~Bureaucrat(void);
		Bureaucrat const &operator = (Bureaucrat const &obj);
		class GradeTooHighException : public std::exception {
			public :
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public :
				const char* what() const throw();
		};
		void		set_grade( int grade_ );
		std::string getName(void) const ;
		int			getGrade(void) const ;
		void	increment_grade();
		void	decrement_grade();
		void	signForm(Form &sign);
};
std::ostream &operator<<(std::ostream& os, const Bureaucrat& obj);

#endif