#ifndef CHANNEL_HPP
# define CHANNEL_HPP

#include <iostream>
#include <vector>
#include <sstream>
#define JOIN "join"
#define MODE "mode"

#define BLUE      "\x1b[34m"
#define ORANGE    "\x1b[33m"
#define RESET     "\x1b[0m"
#define PURPLE    "\x1b[96m"
#define GREEN     "\x1b[32m"
#define RED       "\x1b[1;31m"
#define	st_			std::string
#define CHANNEL '#'
#define POS_KEY '+'
#define NEG_KEY '-'

class channel
{
	public :
		std::vector < std::string > channels;
		std::vector < std::string > channels_pass;
	public :
		channel(void);
		~channel(void);
		void	channel_parse(std::string str);
		void	mode_parse(std::string str);
};

#endif