#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private :
		std::string Name;
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
		std::string getName(void) const ;
		int			getGrade(void) const ;
		void	increment_grade();
		void	decrement_grade();
};
std::ostream &operator<<(std::ostream& os, const Bureaucrat& obj);

#endif