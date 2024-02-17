#pragma once

#include <iostream>
#include <map>
#include <fstream>

class BitcoinExchange {
	private :
		std::map<std::string, std::string> data;
	public:
		void	read_file();
		void	parse_data(std::string Name);
};