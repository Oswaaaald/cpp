#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <sstream>
# include <iostream>
# include <stdexcept>
# include <cstdlib>

class RPN
{
	private:
		std::stack<int> _stack;

		bool isOperator(const std::string &token) const;
		void applyOperator(const std::string &op);

	public:
		RPN();
		RPN(const RPN &copy);
		RPN &operator=(const RPN &copy);
		~RPN();

		int compute(const std::string &expression);
};

#endif