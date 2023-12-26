#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	Bureaucrat	pr("abmoula", 72);
	AForm	*pt =  new ShrubberyCreationForm("sma3in");
	AForm	*pts = new RobotomyRequestForm("sma3in");
	AForm	*pte = new PresidentialPardonForm("sma3in");
	pr.executeForm(*pt);
	pr.executeForm(*pts);
	pr.executeForm(*pte);
}