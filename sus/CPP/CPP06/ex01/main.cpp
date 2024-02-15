#include "Serializer.hpp"

int main() {
	Data obj;
	Serializer ser;
	uintptr_t  ptr;
	obj.str = "Hello world";
	std::cout << obj.str << std::endl;
	ptr = ser.serialize(&obj);
	std::cout << ptr << std::endl;
	obj = *ser.deserialize(ptr);
	std::cout << obj.str << std::endl;
	printf("- > %lu\n", sizeof(Data *));
	printf(" - > %lu\n", sizeof(uintptr_t));
}
