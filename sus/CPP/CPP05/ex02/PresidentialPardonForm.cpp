#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) {
	
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) {
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm const	&PresidentialPardonForm::operator = (PresidentialPardonForm const &rhs) {
	return (*this);
}