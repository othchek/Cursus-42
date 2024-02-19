#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>

class RPN
{
	private :
		std::stack<int> data;
	public :
		RPN(void);
		RPN(RPN const &copy);
		~RPN(void);
		RPN const &operator = (RPN const &rhs);
		void	push(std::string str);
		bool 	isoperator(char c);
		void	exec(char op);
};

#endif