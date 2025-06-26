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

		typedef typename std::stack<T>::container_type::iterator iterator;

		// c comes from std::stack<T>, and is a container_type
		iterator begin()
		{
			return this->c.begin();
		}

		iterator end()
		{
			return this->c.end();
		}
};

#endif