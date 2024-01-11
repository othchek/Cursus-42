#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(ScalarConverter const &copy) {
	*this = copy;
}

ScalarConverter::~ScalarConverter(void) {}

ScalarConverter const	&ScalarConverter::operator = (ScalarConverter const &rhs) {
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

bool	specialcases(std::string special) {
	std::string array[6] = {"nan", "nanf", "-inff", "+inff", "-inf", "+inf"};
	for (int index = 0; index < 6; index++) {
		if (special == array[index]) {
			std::cout << "Char : " << "impossible" << std::endl;
			std::cout << "Int : " << " impossible" << std::endl;
			switch (index) {
				case 0:
					std::cout << "Float : " << array[0] << 'f' << std::endl;
					std::cout << "Double : " << array[0] << std::endl;
					break;
				case 1:
					std::cout << "Float : " << array[1].substr(0, array[1].length() - 1) << 'f' << std::endl;
					std::cout << "Double : " << array[1].substr(0, array[1].length() - 1) << std::endl;
					break;
				case 2:
					std::cout << "Float : " << array[2] << std::endl;
					std::cout << "Double : " << array[2].substr(0, array[2].length() - 1) << std::endl;
					break;
				case 3:
					std::cout << "Float : " << array[3] << std::endl;
					std::cout << "Double : " << array[3].substr(0, array[3].length() - 1) << std::endl;
					break;
				case 4:
					std::cout << "Float : " << array[4] << 'f' << std::endl;
					std::cout << "Double : " << array[4] << std::endl;
					break;
				case 5:
					std::cout << "Float : " << array[5] << 'f' << std::endl;
					std::cout << "Double : " << array[5] << std::endl;
					break;
			}
			return (true);
		}
	}
	return (false);
}

void	ScalarConverter::castfun(std::string convert) {
	
	if (specialcases(convert))
		return ;
	std::stringstream strim(convert);
	try {
		for (int index = 0; convert[index]; index++) {
			if (convert[index] && (isdigit(convert[index]) || convert[index] == '-')) {
				while (convert[index]) {
					if (convert[index] == '.') {
						if (!Floatcheck(convert))
							throw (99.99);
						throw (99.99f);
					}
					index++;
				}
				throw (69);
			}
			else if (convert.length() == 1)
				throw ('c');
		}
	}
	catch(int) {
		int num;
		if (!(strim >> num))
			return std::cerr << "Overflow!!" << std::endl, (void)0;

		if (num <= 32) {
        	std::cout << "Char : " << "Non Displayable" << std::endl;
			std::cout << "Int : " << static_cast<int>(num) << std::endl;
        	std::cout << "Float : " << static_cast<float>(num) << 'f' << std::endl;
        	std::cout << "Double : " << static_cast<double>(num) << std::endl;
		}
		else {
        	std::cout << "Char : " << static_cast<char>(num) << std::endl;	
        	std::cout << "Int : " << static_cast<int>(num) << std::endl;
        	std::cout << "Float : " << static_cast<float>(num) << 'f' << std::endl;
        	std::cout << "Double : " << static_cast<double>(num) << std::endl;
		}
	}
	catch (double) {
		double dub;
		if (!(strim >> dub))
			return std::cerr << "Overflow!!" << std::endl, (void)0;

		if (dub < 33) {
    		std::cout << "Char : " << "Non Displayable" << std::endl;
			std::cout << "Int : " << static_cast<int>(dub) << std::endl;
    		std::cout << "Float : " << static_cast<float>(dub) << 'f' << std::endl;
    		std::cout << "Double : " << dub << std::endl;
		}
		else {
    		std::cout << "Char : " << static_cast<char>(dub) << std::endl;
    		std::cout << "Int : " << static_cast<int>(dub) << std::endl;
    		std::cout << "Float : " << static_cast<float>(dub) << 'f' << std::endl;
    		std::cout << "Double : " << dub << std::endl;
		}
	}
	catch (float) {
		float fl;
		std::stringstream flawat(convert.substr(0, convert.length() - 1));
		if (!(flawat >> fl))
			return std::cerr << "Overflow!!" << std::endl, (void)0;

		if (fl < 33) {
        	std::cout << "Char : " << "Non Displayable" << std::endl;
			std::cout << "Int : " << static_cast<int>(fl) << std::endl;
        	std::cout << "Float : " << fl << 'f' << std::endl;
        	std::cout << "Double : " << static_cast<double>(fl) << std::endl;
		}
		else {
        	std::cout << "Char : " << static_cast<char>(fl) << std::endl;
        	std::cout << "Int : " << static_cast<int>(fl) << std::endl;
        	std::cout << "Float : " << fl << 'f' << std::endl;
        	std::cout << "Double : " << static_cast<double>(fl) << std::endl;
		}
	}
	catch (char) {
		std::cout << "Char : " << convert[0] << std::endl;
		std::cout << "Int : " << static_cast<int>(convert[0]) << std::endl;
		std::cout << "Float : " << static_cast<float>(convert[0]) << 'f' << std::endl;
		std::cout << "Double : " << static_cast<double>(convert[0]) << std::endl;
	}
}