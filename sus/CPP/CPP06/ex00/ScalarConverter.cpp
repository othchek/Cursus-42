#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {
	std::cout << "ScalarConverter Default constructor" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &copy) {
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = copy;
}

ScalarConverter::~ScalarConverter(void) {
	std::cout << "ScalarConverter Destructor" << std::endl;
}

ScalarConverter const	&ScalarConverter::operator = (ScalarConverter const &rhs) {
	std::cout << "ScalarConverter Copy assignment operator called" << std::endl;
	if (this == &rhs) {
        return *this;
    }
    return (*this);
}

void	int_convert(std::string number) {
	
}

void	ScalarConverter::castfun(std::string convert) {
	std::cout << convert << std::endl;
	// std::string array[8] = {"char", "int", "float", "double", "nan", "nanf", "-inff", "+inff"};
}