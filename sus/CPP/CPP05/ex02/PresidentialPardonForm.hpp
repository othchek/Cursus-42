#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#define BLUE      "\x1b[34m"
#define ORANGE    "\x1b[33m"
#define RESET     "\x1b[0m"
#define PURPLE    "\x1b[96m"
#define GREEN     "\x1b[32m"
#define RED       "\x1b[1;31m"

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private :
		std::string target;
	public :
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string target_);
		PresidentialPardonForm(PresidentialPardonForm const &copy);
		~PresidentialPardonForm(void);
		PresidentialPardonForm const &operator = (PresidentialPardonForm const &rhs);
		void		execute(Bureaucrat const & executor) const;
};

#endif