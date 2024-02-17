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
			data = new T[copy.length];
			*this = copy;
		};

		~Array(void) {
			delete[] data;
		};

		size_t	size(void) {
			return (length);
		};

		Array const &operator = (Array const &rhs) {
			length = rhs.length;
			if (data)
				delete[] data;
			data = new T[length];
			for (size_t i = 0; i < length; i++)
				data[i] = rhs[i];
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