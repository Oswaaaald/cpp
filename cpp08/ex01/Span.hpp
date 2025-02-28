#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _numbers;

	public:
		Span(unsigned int n);
		Span(const Span &copy);
		~Span();
		Span &operator=(const Span &copy);

		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		void addFullNumbers(int *begin, int *end);
};

#endif