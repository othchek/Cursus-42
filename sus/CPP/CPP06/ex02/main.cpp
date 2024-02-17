#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int main() {
	Base obj;

	obj.identify(obj.generate());
	obj.identify(*obj.generate());
}