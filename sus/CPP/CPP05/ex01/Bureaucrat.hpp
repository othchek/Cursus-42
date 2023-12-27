#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

#define BLUE      "\x1b[34m"
#define ORANGE    "\x1b[33m"
#define RESET     "\x1b[0m"
#define PURPLE    "\x1b[96m"
#define GREEN     "\x1b[32m"
#define RED       "\x1b[1;31m"

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