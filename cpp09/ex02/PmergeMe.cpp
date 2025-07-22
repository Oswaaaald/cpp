#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &copy) : _vector(copy._vector), _deque(copy._deque)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy)
{
	if (this != &copy)
	{
		this->_vector = copy._vector;
		this->_deque = copy._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

bool PmergeMe::_isNumeric(const std::string &str)
{
	for (size_t i = 0; i < str.length(); ++i)
		if (!std::isdigit(str[i]))
			return false;
	return true;
}

void PmergeMe::parseInput(int argc, char **argv)
{
	for (int i = 1; i < argc; ++i)
	{
		std::string arg(argv[i]);
		if (!_isNumeric(arg))
			throw std::runtime_error("Error");
		int value = std::atoi(argv[i]);
		if (value < 0)
			throw std::runtime_error("Error");
		_vector.push_back(value);
		_deque.push_back(value);
	}
}

static std::vector<size_t> getJacobsthalOrder(size_t size)
{
	std::vector<size_t> order;
	std::vector<bool> used(size, false);

	for (size_t j1 = 1, j2 = 1; j2 < size; )
	{
		order.push_back(j2);
		used[j2] = true;
		size_t tmp = j2;
		j2 = j2 + 2 * j1;
		j1 = tmp;
	}

	for (size_t i = 0; i < size; ++i)
		if (!used[i])
			order.push_back(i);
	return order;
}

void PmergeMe::_fordJohnsonVector(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return;

	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < vec.size(); i += 2)
	{
		if (vec[i] < vec[i + 1])
			std::swap(vec[i], vec[i + 1]);
		pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
	}

	std::vector<int> chain;
	for (size_t i = 0; i < pairs.size(); ++i)
		chain.push_back(pairs[i].first);
	_fordJohnsonVector(chain);

	std::vector<std::pair<int, int> > pend = pairs;
	if (vec.size() % 2 != 0)
		pend.push_back(std::make_pair(-1, vec.back()));

	std::vector<size_t> order = getJacobsthalOrder(pend.size());

	for (size_t k = 0; k < order.size(); ++k)
	{
		size_t idx = order[k];
		int y = pend[idx].second;
		int x = pend[idx].first;

		std::vector<int>::iterator upper = chain.end();
		if (x != -1)
		{
			std::vector<int>::iterator it = std::find(chain.begin(), chain.end(), x);
			if (it != chain.end())
				upper = ++it;
		}
		std::vector<int>::iterator pos = std::lower_bound(chain.begin(), upper, y);
		chain.insert(pos, y);
	}
	vec = chain;
}

void PmergeMe::_fordJohnsonDeque(std::deque<int> &deq)
{
	if (deq.size() <= 1)
		return;

	std::vector<std::pair<int, int> > pairs;
	for (size_t i = 0; i + 1 < deq.size(); i += 2)
	{
		if (deq[i] < deq[i + 1])
			std::swap(deq[i], deq[i + 1]);
		pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
	}

	std::deque<int> chain;
	for (size_t i = 0; i < pairs.size(); ++i)
		chain.push_back(pairs[i].first);
	_fordJohnsonDeque(chain);

	std::vector<std::pair<int, int> > pend = pairs;
	if (deq.size() % 2 != 0)
		pend.push_back(std::make_pair(-1, deq.back()));

	std::vector<size_t> order = getJacobsthalOrder(pend.size());

	for (size_t k = 0; k < order.size(); ++k)
	{
		size_t idx = order[k];
		int y = pend[idx].second;
		int x = pend[idx].first;

		std::deque<int>::iterator upper = chain.end();
		if (x != -1)
		{
			std::deque<int>::iterator it = std::find(chain.begin(), chain.end(), x);
			if (it != chain.end())
				upper = ++it;
		}
		std::deque<int>::iterator pos = std::lower_bound(chain.begin(), upper, y);
		chain.insert(pos, y);
	}
	deq = chain;
}

void PmergeMe::sortAndDisplay()
{
	std::cout << "Before: ";
	for (size_t i = 0; i < _vector.size(); ++i)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;

	clock_t startVec = clock();
	_fordJohnsonVector(_vector);
	clock_t endVec = clock();

	clock_t startDeq = clock();
	_fordJohnsonDeque(_deque);
	clock_t endDeq = clock();

	std::cout << "After: ";
	for (size_t i = 0; i < _vector.size(); ++i)
		std::cout << _vector[i] << " ";
	std::cout << std::endl;

	double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
	double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

	std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : " << std::fixed << std::setprecision(5) << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque  : " << std::fixed << std::setprecision(5) << timeDeq << " us" << std::endl;
}