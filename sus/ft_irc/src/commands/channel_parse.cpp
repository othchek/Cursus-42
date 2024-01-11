#include "../../inc/channel.hpp"

channel::channel(void) {}

channel::~channel(void) {}

int	f_stoi( std::string numb ) {
	int		ret;

	std::stringstream var(numb);
	var >> ret;
	return ret;
}

void	channel::channel_parse(std::string str) {
	char *p;
	std::string command = str.substr(0, str.find(" "));
	if (str.substr(0, std::string(JOIN).length()) == JOIN)
		str.erase(0, std::string(JOIN).length() + 1);
	else if (str.substr(0, std::string(MODE).length()) == MODE) {
		str.erase(0, std::string(MODE).length() + 1);
		mode_parse(str);
		return ;
	}
	else
		throw ("Unknown command");
	int i = 0;
	p = std::strtok(const_cast<char *>(str.c_str()), ", \r\n");
	while (p != NULL) {
		if (p[0] == '#') {
			std::vector < std::string >::iterator pos = std::find(channels.begin(), channels.end(), p);
			if (pos != channels.end())
				throw ("Duplicate channel");
			channels.push_back(p);
			i++;
		}
		else
			channels_pass.push_back(p);
		p = std::strtok(NULL, ", \n");
	}
	if (channels.empty() || i == 0)
		throw ("command alone can't function");
	// for (std::vector < std::string >::iterator it_ = channels.begin(); it_ != channels.end(); it_++)
	// 	std::cout << "channels : " << *it_ << std::endl;
	// std::cout << "command : " << command << std::endl;
	// for (std::vector < std::string >::iterator iti_ = channels_pass.begin(); iti_ != channels_pass.end(); iti_++)
	// 	std::cout << "passwords : " << *iti_ << std::endl;
}

void	channel::mode_parse(std::string str) {
	char *p;
	std::string mode_pass;
	std::string key;
	std::string channel;

	p = std::strtok(const_cast<char *>(str.c_str()), " ");
	while (p != NULL) {
		if (p[0] == CHANNEL && channel.empty())
			channel = p;
		else if ((p[0] == POS_KEY || p[0] == NEG_KEY) && key.empty())
			key = p;
		else if (p[0] != NEG_KEY && p[0] != POS_KEY && p[0] != CHANNEL && mode_pass.empty())
			mode_pass = p;
		p = std::strtok(NULL, ", ");
	}
	std::vector < std::string >::iterator pos = std::find(channels.begin(), channels.end(), channel);
	if (pos == channels.end())
		throw ("Channel not found");
	// std::cout << "channel : " << channel << std::endl;
	// std::cout << "key : " << key << std::endl;
	// std::cout << "password : " << mode_pass << std::endl;
}