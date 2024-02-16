#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
	private :
		T 	  *data;
		size_t length;
	public :
		Array(void) {
			data = new T[0],
			length = 0;
		};
		Array(unsigned int n) {data = new T[n], length = n;}
		class sub : public std::exception {
			public :
				const char *what() const throw() {
					return ("Error Out of Bounds");
				}
		};
		Array(Array const &copy) {
			*this = copy;
		};
		~Array(void) {};
		size_t	size(void) {
			return (length);
		};
		Array const &operator = (Array const &rhs) {
			data = rhs.data;
			length = rhs.length;
			return *this;
		};
		T& operator[]( unsigned int i ) {
			if (i >= length)
				throw (sub());
			return (data[i]);
		}
		const T &operator[]( unsigned int i ) const {
			if (i >= length)
				throw (sub());
			return (data[i]);
		}
};

#endif