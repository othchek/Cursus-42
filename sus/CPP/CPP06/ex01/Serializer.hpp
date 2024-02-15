#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
struct Data {
	std::string str;
};

class Serializer
{
	public :
		Serializer(void);
		Serializer(Serializer const &copy);
		~Serializer(void);
		Serializer const &operator = (Serializer const &rhs);
		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
};

#endif