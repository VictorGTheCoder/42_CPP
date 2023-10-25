#include "MutantStack.hpp"
#include "MutantStack.tpp"

int main()
{
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
		//[...]
		mstack.push(0);
		MutantStack<int>::myiterator it = mstack.begin();
		MutantStack<int>::myiterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << "<------- List ------>" << std::endl;
	{
		std::list<int> mylist;
		mylist.push_back(5);
		mylist.push_back(17);
		std::cout << mylist.back() << std::endl;
		mylist.pop_front();
		std::cout << mylist.size() << std::endl;
		mylist.push_back(3);
		mylist.push_back(5);
		mylist.push_back(737);
		//[...]
		mylist.push_back(0);
		std::list<int>::iterator it = mylist.begin();
		std::list<int>::iterator ite = mylist.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mylist);
	}
	{
		std::cout << "<------- Copy ------>" << std::endl;

		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(3);

		MutantStack<int> cpy(mstack);

		mstack.pop();

		MutantStack<int>::myiterator it = mstack.begin();
		MutantStack<int>::myiterator ite = mstack.end();
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "-------------" << std::endl;
		MutantStack<int>::myiterator itc = cpy.begin();
		MutantStack<int>::myiterator itec = cpy.end();
		while (itc != itec)
		{
			std::cout << *itc << std::endl;
			++itc;
		}
	}
	return 0;

}