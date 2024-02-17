#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::it its = mstack.begin();
	MutantStack<int>::it ite = mstack.end();
	++its;
	--its;
	while (its != ite)
	{
		std::cout << *its << std::endl;
		++its;
	}
	std::stack<int> s(mstack);
	return 0;
}