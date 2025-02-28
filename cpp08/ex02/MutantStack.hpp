#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {}
		MutantStack(const MutantStack &copy) : std::stack<T>(copy) {}
		~MutantStack() {}
		MutantStack &operator=(const MutantStack &copy)
		{
			std::stack<T>::operator=(copy);
			return *this;
		}

		// allows to use the iterator of the container_type of the stack
		typedef typename std::stack<T>::container_type::iterator iterator;

		// c comes from std::stack<T>, and is a container_type
		// send an iterator to the beginning of the container (first element of the stack)
		iterator begin()
		{
			return this->c.begin();
		}
		// send an iterator to the end of the container (last element of the stack)
		iterator end()
		{
			return this->c.end();
		}
};

#endif