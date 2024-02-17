#include "Serializer.hpp"

int main() {
	Data	*ptr = new Data;
	ptr->str = "hello world";
	std::cout  << "before : " << ptr->str << std::endl;
	uintptr_t sto = Serializer::serialize(ptr);
	ptr = Serializer::deserialize(sto);
	std::cout  << "after : " << ptr->str << std::endl;
	delete ptr;
}