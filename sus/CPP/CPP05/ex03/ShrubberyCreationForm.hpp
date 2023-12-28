#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#define RESET     "\x1b[0m"
#define GREEN     "\x1b[32m"
#define RED       "\x1b[1;31m"

#include "AForm.hpp"
#include <fstream>
#include <iostream>

class ShrubberyCreationForm : public AForm {
	private :
		std::string target;
	public :
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target_);
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		~ShrubberyCreationForm(void);
		ShrubberyCreationForm const &operator = (ShrubberyCreationForm const &rhs);
		void	execute(Bureaucrat const & executor) const;
};

#endif