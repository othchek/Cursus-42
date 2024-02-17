#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>

#define BLUE      "\x1b[34m"
#define ORANGE    "\x1b[33m"
#define RESET     "\x1b[0m"
#define PURPLE    "\x1b[96m"
#define GREEN     "\x1b[32m"
#define RED       "\x1b[1;31m"

class ScalarConverter
{
	private :
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &copy);
		ScalarConverter const &operator = (ScalarConverter const &rhs);
	public :
		~ScalarConverter(void);
		static void castfun(std::string thing);
};

#endif