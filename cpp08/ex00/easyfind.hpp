#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <iterator>
# include <vector>
# include <list>

class NoOccurenceFound : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return "No occurence found";
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw NoOccurenceFound();
	return it;
}

#endif