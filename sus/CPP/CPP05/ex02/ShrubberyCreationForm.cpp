#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("abmoula", 145, 137) {
	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
	target = "shribiribiri";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target_) : AForm("abmoula", 145, 137) {
	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
	target = target_;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm const	&ShrubberyCreationForm::operator = (ShrubberyCreationForm const &rhs) {
	std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
	if (this == &rhs) {
        return *this;
    }
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!get_signed() && executor.getGrade() > get_sign_Grade())
		throw GradeTooLowException();
	std::ofstream file(target + "_shrubbery");
	if (file.is_open()) {
		file << "                                  		   |\n";
		file << "                                  ________|________\n";
		file << "                                 |                 |\n";
		file << "              ________________   A   ________________\n";
		file << "             |              | / \\ |                |\n";
		file << "          ___B___        ___C___ D ___D___       __E__\n";
		file << "         |       |      |       |        |     |     |\n";
		file << "        F       G      H       I        J     K     L\n";
		file << "       / \\     / \\    / \\     / \\      / \\   / \\   / \\\n";
		file << "      M   N   O   P  Q   R   S   T    U   V W   X Y   Z\n";
		file.close();
		std::cout << GREEN << "A tree is successfully created and saved to the file." << RESET << std::endl;
	}
	else
		std::cout << RED << "Error opening file" << RESET << std::endl;
}