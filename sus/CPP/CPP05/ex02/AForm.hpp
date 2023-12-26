#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private :
		std::string const Name;
		bool			  is_signed;
		int const		  sign;
		int const 		  exec;
	public :
		AForm(void);
		AForm(std::string Name_, int sign_grade_, int exec_grade_);
		AForm(AForm const &copy);
		virtual ~AForm(void);
		AForm const &operator = (AForm const &obj);
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
		bool		get_signed(void) const;
		std::string getName(void) const ;
		int			get_sign_Grade(void) const ;
		int			get_exec_Grade(void) const ;
		void		beSigned(Bureaucrat &obj);
		virtual void		execute(Bureaucrat const & executor) const = 0;
};
std::ostream &operator<<(std::ostream& os, const AForm& obj);
#endif