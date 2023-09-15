#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <algorithm>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack& src);

		typedef typename std::stack<T>::container_type::iterator myiterator;
		myiterator begin()
		{
			return this->c.begin();
		}
		myiterator end()
		{
			return this->c.end();
		}
		MutantStack& operator=(const MutantStack& rhs);
};

#endif