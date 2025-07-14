#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <iomanip>
# include <algorithm>

class PmergeMe
{
	private:
		std::vector<int> _vector;
		std::deque<int> _deque;

		bool _isNumeric(const std::string &str);

		void _fordJohnsonVector(std::vector<int> &vec);
		void _fordJohnsonDeque(std::deque<int> &deq);

	public:
		PmergeMe();
		PmergeMe(const PmergeMe &copy);
		PmergeMe &operator=(const PmergeMe &copy);
		~PmergeMe();

		void parseInput(int argc, char **argv);
		void sortAndDisplay();
};

#endif