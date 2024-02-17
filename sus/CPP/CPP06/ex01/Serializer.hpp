#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
struct Data {
	std::string str;
};

class Serializer
{
	private :
		Serializer(void);
		Serializer(Serializer const &copy);
		Serializer const &operator = (Serializer const &rhs);
	public :
		~Serializer(void);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif