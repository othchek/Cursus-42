#pragma once

#include <iostream>
#include <map>
#include <fstream>
#include <exception>
#include <sstream>

class BitcoinExchange {
	private :
		std::map<std::string, std::string> data;
		std::string Year;
		std::string Month;
		std::string Day;
		std::string Value;
	public:
        std::string&    ltrim(std::string& str);
        std::string&    rtrim(std::string& str);
        std::string&    trim(std::string& str);
		void			read_file();
		void			read_input(std::string Name);
		void			parse_date(std::string Date);
		void			parse_value(std::string Value);
};