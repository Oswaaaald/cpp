#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <cstdlib>

template <typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	_size;
	public:
		Array() : _array(NULL), _size(0) {}
		Array(unsigned int n) : _array(new T[n]()), _size(n) {}
		Array(const Array &copy) : _size(copy._size)
		{
			this->_array = new T[copy._size];
			for (unsigned int i = 0; i < copy._size; i++)
				this->_array[i] = copy._array[i];
		}
		~Array()
		{
			delete[] this->_array;
		}
		Array &operator=(const Array &copy)
		{
			if (this != &copy)
			{
				delete[] this->_array;
				this->_size = copy._size;
				this->_array = new T[copy._size];
				for (unsigned int i = 0; i < copy._size; i++)
					this->_array[i] = copy._array[i];
			}
			return *this;
		}
		T &operator[](unsigned int i)
		{
			if (i >= this->_size)
				throw std::out_of_range("Index out of range");
			return this->_array[i];
		}
		const T &operator[](unsigned int i) const
		{
			if (i >= this->_size)
				throw std::out_of_range("Index out of range");
			return this->_array[i];
		}
		unsigned int size() const
		{
			return this->_size;
		}
};

#endif