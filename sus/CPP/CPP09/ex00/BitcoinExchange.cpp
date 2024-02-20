#include "BitcoinExchange.hpp"
#include <unistd.h>

BitcoinExchange const	&BitcoinExchange::operator = (BitcoinExchange const &rhs)
{
	if (this == &rhs) {
		this->data = rhs.data;
		this->Day = rhs.Day;
		this->Month = rhs.Month;
		this->Year = rhs.Year;
		this->Value = rhs.Value;
        return *this;
    }	
	return (*this);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy)
{
	*this = copy;
}

int BitcoinExchange::isLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

void BitcoinExchange::isValidDate()
{
	int year = f_stoi(Year);
	int month = f_stoi(Month);
	int day = f_stoi(Day);
    if (year < 0 || year < 2009 || month < 1 || month > 12 || day < 1)
		throw std::invalid_argument("Error: Invalid Date!!");

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (isLeapYear(year))
        daysInMonth[1] = 29;

    if (day > daysInMonth[(int)month - 1])
        throw std::invalid_argument("Error: Invalid Date!!");
}

int BitcoinExchange::f_stoi(std::string numb)
{
	int ret;

	std::stringstream var(numb);
	if (!(var >> ret))
		throw ("Error: Overflow\n");
	return ret;
}

std::string& BitcoinExchange::ltrim(std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    if (start != std::string::npos) {
        str.erase(0, start);
    } else {
        str.clear();
    }
    return str;
}

std::string& BitcoinExchange::rtrim(std::string& str) {
    size_t end = str.find_last_not_of(" \t\n\r");
    if (end != std::string::npos) {
        str.erase(end + 1);
    } else {
        str.clear();
    }
    return str;
}

std::string& BitcoinExchange::trim(std::string& str) {
    return ltrim(rtrim(str));
}

void	BitcoinExchange::read_file() {
	std::string str;
	std::string date;
	std::ifstream file;
	file.open("data.csv");
	if (!file.is_open()) {
		std::cout << "file not found!!" << std::endl;
		exit (1);
	}
	getline(file, str);
	while (std::getline(file, str)) 
	{
		size_t pos = str.find(',');
		if (pos != std::string::npos)
			date = str.substr(0, pos - 1);
		data.insert(std::make_pair(date, str.substr(pos + 1)));
	}
}

void BitcoinExchange::read_input(std::string Name) {
	std::string str;
	std::string date;
	std::string value;
	std::ifstream file;
	file.open(Name);
	if (!file.is_open()) {
		std::cout << "file not found!!" << std::endl;
		exit (1); 
	}
	getline(file, str);
	if (file.eof() || str.compare("date | value"))
		throw (std::invalid_argument("Invalid file!!"));
	while (std::getline(file, str))
	{
		try {
			if (str.length() < 14)
				throw (std::invalid_argument("Error: Invalid Date/Value!!"));
			size_t pos = str.find('|');
			size_t rpos = str.rfind('|');
			if (pos != rpos)
				throw (std::invalid_argument("Error: Invalid data[multiple Pipes!!]"));
			date = str.substr(0, pos);
			if (date.length() != 11)
				throw (std::invalid_argument("Error: Invalid Date!!"));
			value = str.substr(pos + 1);
			store_date(date);
			parse_value(value);
			isValidDate();
			std::map < std::string, std::string >::iterator it = data.lower_bound(date);
			if (it != data.end())
				std::cout << date << "=>" << value << " = " << f_atof(value.c_str()) * f_atof(it->second.c_str()) << std::endl;
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
			continue;
		}
	}
}

void BitcoinExchange::store_date(std::string Date) {
	char *p;
	hiphen_check(Date);
	p = std::strtok(const_cast<char *>(Date.c_str()), "-");
	int count = 0;
	
	while (p != NULL)
	{
		if (std::string(p).length() == 4)
			Year = p;
		else
		{
			if (count == 0)
				Month = p;
			else if (count == 1)
				Day = p;
			else
				throw (std::invalid_argument("Error: Invalid Date!!"));
			count++;
		}
		p = std::strtok(NULL, "-");
	}
}

float BitcoinExchange::f_atof(std::string Value) {
	float ret = 0.0f;
    Value = trim(Value);
    std::stringstream var(Value);
	if (!(var >> ret))
        throw std::invalid_argument("Error: Overflow!!");
	return ret;
}

void BitcoinExchange::parse_value(std::string Value) {
    float ret = 0.0f;
    Value = trim(Value);
    std::stringstream var(Value);
    if (std::count(Value.begin(), Value.end(), '.') > 1)
        throw std::invalid_argument("Error: Invalid Value!!");
    for (int i = 0; (size_t)i < Value.length(); i++) {
        if ((std::isdigit(Value[i]) == 0 && Value[i] != '.') || typeid(Value) == typeid(float))
            throw std::invalid_argument("Error: Invalid Value!!");
    }
    if (!(var >> ret))
        throw std::invalid_argument("Error: Overflow!!");
    if (ret < 0.0f || ret >= 1000.1f)
        throw std::invalid_argument("Error: Invalid Value!!");
    this->Value = Value;
}

void BitcoinExchange::hiphen_check(std::string Date) {
	int count = 0;
	for (int i = 0; Date[i]; i++) {
		if (Date[i] == '-' && std::isdigit(Date[i - 1]) && std::isdigit(Date[i + 1]))
			count++;
	}
	if (count != 2)
		throw std::invalid_argument("Error: Invalid Date!!");
}

// void BitcoinExchange::parse_date() {
// 	int year = f_stoi(Year);
// 	int month = f_stoi(Month);
// 	int day = f_stoi(Day);
// 	if (year < 2009)
// 		throw std::invalid_argument("Error: Invalid Year!!");
// 	if (month < 01 || month > 12)
// 		throw std::invalid_argument("Error: Invalid Month!!");
// 	if (day < 01)
// 		throw std::invalid_argument("Error: Invalid Day!!");
// }