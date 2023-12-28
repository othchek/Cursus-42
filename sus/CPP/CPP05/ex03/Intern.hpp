#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define BLUE      "\x1b[34m"
#define ORANGE    "\x1b[33m"
#define RESET     "\x1b[0m"
#define PURPLE    "\x1b[96m"
#define GREEN     "\x1b[32m"
#define RED       "\x1b[1;31m"

class Intern
{
	public :
		Intern(void);
		Intern(Intern const &copy);
		~Intern(void);
		Intern const &operator = (Intern const &rhs);
		AForm *makeForm(std::string FormName, std::string FormTarget);
};

#endif