#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#define BLUE      "\x1b[34m"
#define ORANGE    "\x1b[33m"
#define RESET     "\x1b[0m"
#define PURPLE    "\x1b[96m"
#define GREEN     "\x1b[32m"
#define RED       "\x1b[1;31m"

#include "AForm.hpp"
#include <time.h>

class RobotomyRequestForm : public AForm {
	private :
		std::string target;
	public :
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string target_);
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		~RobotomyRequestForm(void);
		RobotomyRequestForm const &operator = (RobotomyRequestForm const &rhs);
		void	execute(Bureaucrat const & executor) const;
};

#endif