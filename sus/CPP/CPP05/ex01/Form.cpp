#include "Form.hpp"

Form::Form(void) {}

Form::Form(Form const &copy) {
	*this = copy;
}

Form::~Form(void) {}

Form const	&Form::operator = (Form const &rhs) {
	return (*this);
}