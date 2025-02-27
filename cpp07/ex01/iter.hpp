#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void iter(T *array, size_t len, void (*f)(T&))
{
	for (size_t i = 0; i < len; i++)
		f(array[i]);
}

template <typename T>
void printValue(T &a)
{
	std::cout << a << std::endl;
}

template <typename T>
void addTen(T &a)
{
	a += 10;
	std::cout << a << std::endl;
}

template <typename T>
void remFive(T &a)
{
	a -= 5;
	std::cout << a << std::endl;
}

#endif