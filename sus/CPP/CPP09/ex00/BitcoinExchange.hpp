#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <exception>
#include <sstream>

class BitcoinExchange {
	private :
		std::map<std::string, std::string> data;
		std::string 					   Year;
		std::string 					   Month;
		std::string 					   Day;
		std::string 					   Value;
	public:
		BitcoinExchange(void) {};
		BitcoinExchange(BitcoinExchange const &copy);
		~BitcoinExchange(void);
		BitcoinExchange const &operator = (BitcoinExchange const &rhs);
        std::string&    ltrim(std::string& str);
        std::string&    rtrim(std::string& str);
        std::string&    trim(std::string& str);
		void			read_file();
		void			read_input(std::string Name);
		void			store_date(std::string Date);
		void			parse_value(std::string Value);
		void			hiphen_check(std::string Date);
		void			parse_date();
		int				f_stoi(std::string numb);
		int				isLeapYear(int year);
		void			isValidDate();
		float			f_atof(std::string Value);
};