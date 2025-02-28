#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	//std::cout << "Check Assign Operator" << std::endl;
	//MutantStack<int> copiedStack = mstack;
	//it = copiedStack.begin();
	//ite = copiedStack.end();
	//while (it != ite)
	//{
	//	std::cout << *it << std::endl;
	//	++it;
	//}
	//
	//std::cout << "Check Copy Constructor" << std::endl;
	//MutantStack<int> copiedStack2(mstack);
	//it = copiedStack2.begin();
	//ite = copiedStack2.end();
	//while (it != ite)
	//{
	//	std::cout << *it << std::endl;
	//	++it;
	//}

	std::stack<int> s(mstack);

	// My tests with List
	std::cout << "My tests with List" << std::endl;
	std::list<int> list;

	list.push_back(5);
	list.push_back(17);

	std::cout << list.back() << std::endl;
	
	list.pop_back();
	
	std::cout << list.size() << std::endl;
	
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	std::list<int>::iterator it2 = list.begin();
	std::list<int>::iterator ite2 = list.end();
	++it2;
	--it2;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}

	return 0;
}