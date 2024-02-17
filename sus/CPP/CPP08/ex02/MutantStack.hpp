#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
	public :
		MutantStack(void) {};
		typedef typename std::deque<T>::iterator it;
		typedef typename std::deque<T>::iterator fend;
		typedef const typename std::deque<T>::iterator c_begin;
		typedef const typename std::deque<T>::iterator c_end;
		it begin() {
			return this->c.begin();
		}
		fend end() {
			return this->c.end();
		}
		c_begin cbegin() const {
			return this->c.cbegin();
		}
		c_end cend() const {
			return this->c.cend();
		}
};

#endif