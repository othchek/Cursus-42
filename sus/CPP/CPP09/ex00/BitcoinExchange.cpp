#include "BitcoinExchange.hpp"

void	BitcoinExchange::read_file() {
	std::string str;
	std::string date;
	std::ifstream file;
	file.open("data.csv");
	getline(file, str);
	while (std::getline(file, str)) 
	{
		size_t pos = str.find(',');
		if (pos != std::string::npos)
			date = str.substr(0, pos - 1);
		data.insert(std::make_pair(date, str.substr(pos + 1)));
	}
	// for (std::map < std::string, std::string >::iterator it = data.begin(); it != data.end(); it++) {
	// 	std::cout << "this is date " << it->first << std::endl;
	// 	std::cout << "this is value " << it->second << std::endl;
	// }
}

void BitcoinExchange::parse_data(std::string Name) {
	std::string str;
	std::ifstream file;
	file.open(Name);
	getline(file, str);
	while (std::getline(file, str)) 
	{
		
	}
}