#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base(void) {
	std::cout << "Base Destructor Called" << std::endl;
}

Base *Base::generate() {
	srand(time(0));
	int value = rand();
	if (value % 3 == 0)
		return (new A);
	else if (value % 3 == 1)
		return (new B);
	return (new C);
}

void  Base::identify(Base *p) {
	Base *ptr = dynamic_cast<A *>(p);
	if (ptr != NULL)
		return (std::cout << "This is a type A" << std::endl, (void)0);
	Base *rtp = dynamic_cast<B *>(p);
	if (rtp != NULL)
		return (std::cout << "This is a type B" << std::endl, (void)0);
	Base *prt = dynamic_cast<C *>(p);
	if (prt != NULL)
		return (std::cout << "This is a type C" << std::endl, (void)0);
}

void  Base::identify(Base& p) {
	Base ptr;
	try {
		ptr = dynamic_cast<A &>(p);
		return (std::cout << "This is a type A" << std::endl, (void)0);
	}
	catch(std::exception &e) {
	}
	try {
		ptr = dynamic_cast<B &>(p);
		return (std::cout << "This is a type B" << std::endl, (void)0);
	}
	catch(std::exception &e) {
	}
	try {
		ptr = dynamic_cast<C &>(p);
		return (std::cout << "This is a type C" << std::endl, (void)0);
	}
	catch(std::exception &e) {
	}

}