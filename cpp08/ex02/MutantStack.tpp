#include "MutantStack.hpp"


template <typename T>
MutantStack<T>::MutantStack(void) {};

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &src)
{        
    *this = src;
};

template <typename T>
MutantStack<T>::~MutantStack<T>(void) {};

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T> &rhs)
{
    this->c = rhs.c;
	return *this;
}