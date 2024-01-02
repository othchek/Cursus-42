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

bool	Floatcheck(std::string number) {
	for (int index = 0; number[index]; index++) {
		if (number[index] == 'f')
			return (true);
	}
	return (false);
}

int charExists(const std::string& myString, char charToFind) {
    return myString.find(charToFind) != std::string::npos ? 1 : 0;
}

void	ScalarConverter::castfun(std::string convert) {
	std::cout << convert << std::endl;
	std::stringstream strim(convert);
	try {
		for (int index = 0; convert[index]; index++) {
			if (convert[index] && (isdigit(convert[index]) || convert[index] == '-')) {
				while (convert[index]) {
					if (convert[index] == '.') {
						if (!Floatcheck(convert))
							throw 99.99;
						throw 99.99f;
					}
					index++;
				}
				throw 69;
			}
			else if (convert.length() == 1)
				throw 'c';
		}
	}
	catch(int) {
		int num;

		strim >> num;
		char harf = static_cast<char>(num);
		std::cout << "Char : " << harf << std::endl;
		std::cout << "Int : " << static_cast<int>(num) << std::endl;
		std::cout << "Float : " << static_cast<float>(num) << 'f' << std::endl;
		std::cout << "Double : " << static_cast<double>(num) << std::endl;
	}
	catch (double) {
		double dub;

		strim >> dub;
		char harf = static_cast<char>(dub);
		std::cout << "Char : " << harf << std::endl;
		std::cout << "Int : " << static_cast<int>(dub) << std::endl;
		std::cout << "Float : " << static_cast<float>(dub) << 'f' << std::endl;
		std::cout << "Double : " << static_cast<double>(dub) << std::endl;
	}
	catch (float) {
		float fl;

		strim >> fl;
		std::cout << "Char : " << static_cast<char>(fl) << std::endl;
		std::cout << "Int : " << static_cast<int>(fl) << std::endl;
		std::cout << "Float : " << static_cast<float>(fl) << 'f' << std::endl;
		std::cout << "Double : " << static_cast<double>(fl) << std::endl;
	}
	catch (char) {
		std::cout << "Char : " << convert[0] << std::endl;
		std::cout << "Int : " << static_cast<int>(convert[0]) << std::endl;
		std::cout << "Float : " << static_cast<int>(convert[0]) << 'f' << std::endl;
		std::cout << "Double : " << static_cast<int>(convert[0]) << std::endl;
	}
}