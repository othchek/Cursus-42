#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private :
		std::string const Name;
		bool			  is_signed;
		int const		  sign_grade;
		int const 		  exec_grade;
	public :
		Form(void);
		Form(std::string Name_, bool is_signed_, int sign_grade_, int exec_grade_);
		Form(Form const &copy);
		~Form(void);
		Form const &operator = (Form const &obj);
		class GradeTooHighException : public std::exception {
			public :
				const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public :
				const char* what() const throw();
		};
		class Checksign : public std::exception {
			public :
				const char* what() const throw();
		};
		bool		get_signed(void);
		std::string getName(void) const ;
		int			get_sign_Grade(void) const ;
		int			get_exec_Grade(void) const ;
		void		beSigned(Bureaucrat &obj);
};
std::ostream &operator<<(std::ostream& os, const Form& obj);
#endif