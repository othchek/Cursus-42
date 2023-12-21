#ifndef FORM_HPP
# define FORM_HPP

class Form
{
	public :
		Form(void);
		Form(Form const &copy);
		~Form(void);
		Form const &operator = (Form const &rhs);
};

#endif