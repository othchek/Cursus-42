#include "RPN.hpp"

RPN::RPN(void) {}

RPN::RPN(RPN const &copy)
{
	*this = copy;
}

RPN::~RPN(void) {}

bool RPN::isoperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

RPN const	&RPN::operator = (RPN const &rhs)
{
	if (this == &rhs) {
        return *this;
    }	
	return (*this);
}

void RPN::exec(char op) {
	if (data.size() < 2)
		throw std::invalid_argument("Error: Insufficient operands");

	int num1 = data.top();
	data.pop();
	int num2 = data.top();
	data.pop();

	switch (op) 
	{
		case '+':
			data.push(num2 + num1);
			break;
		case '-':
			data.push(num2 - num1);
			break;
		case '*':
			data.push(num2 * num1);
			break;
		case '/':
			if (num1 == 0)
				throw std::invalid_argument("Error: Division by zero");
			data.push(num2 / num1);
			break;
		default:
			throw std::invalid_argument("Error: Invalid operator");
	}
}


void RPN::push(std::string str) {
	for (int i = 0; str[i]; i++) {
		if (std::isdigit(str[i]))
			data.push(str[i] - '0');
		else if (!std::isspace(str[i]) && isoperator(str[i]))
                exec(str[i]);
		else if (!std::isspace(str[i]))
			throw std::invalid_argument("Error: Invalid character");
    }
	std::cout << data.top() << std::endl;
}
