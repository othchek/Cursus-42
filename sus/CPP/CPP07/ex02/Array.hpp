#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
	private :
		T *data;
	public :
		Array(void) {data = new T[0]}
		Array(unsigned int n) {data = new T[n];}
		Array(Array const &copy);
		~Array(void);
		void	size(void);
		Array const &operator = (Array const &rhs);
};

#endif