#include "Span.hpp"

Span::Span(unsigned int n) : _n(n)
{
}

Span::Span(const Span &copy) : _n(copy._n), _numbers(copy._numbers)
{
}

Span::~Span()
{
}

Span &Span::operator=(const Span &copy)
{
	if (this == &copy)
		return *this;
	this->_n = copy._n;
	this->_numbers = copy._numbers;
	return *this;
}

void Span::addNumber(int n)
{
	if (this->_numbers.size() >= this->_n)
		throw std::logic_error("Span is full");
	this->_numbers.push_back(n);
}

int Span::shortestSpan()
{
	if (this->_numbers.size() <= 1)
		throw std::logic_error("Not enough numbers to calculate span");
	std::vector<int> sorted = this->_numbers;
	std::sort(sorted.begin(), sorted.end());
	int shortest = sorted[1] - sorted[0];
	for (size_t i = 1; i < sorted.size(); i++)
	{
		if (sorted[i] - sorted[i - 1] < shortest)
			shortest = sorted[i] - sorted[i - 1];
	}
	return shortest;
}

int Span::longestSpan()
{
	int max;
	int min;
	if (this->_numbers.size() <= 1)
		throw std::logic_error("Not enough numbers to calculate span");
	std::vector<int> sorted = this->_numbers;
	std::sort(sorted.begin(), sorted.end());
	max = *std::max_element(sorted.begin(), sorted.end());
	min = *std::min_element(sorted.begin(), sorted.end());
	return max - min;
}

// Insert all numbers between begin's and end's addresses (end not included) into the vector after its last element
void Span::addFullNumbers(int *begin, int *end)
{
	if (this->_numbers.size() + (end - begin) > this->_n)
		throw std::logic_error("Span is full");
	this->_numbers.insert(this->_numbers.end(), begin, end);
}