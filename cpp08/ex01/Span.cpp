#include "Span.hpp"


Span::Span(unsigned int N) : _size(N), _container(0) {};

void Span::addNumber(unsigned int new_n)
{
	if (_size > 0)
	{
		_size --;
		_container.push_back(new_n);
	}
	else
	{
		throw std::out_of_range("Error: Container is full");
	}
}

int Span::shortestSpan(void)
{
	if (_container.size() < 2)
		throw std::out_of_range("Error: Container need at least 2 elements");

	std::vector<int> sortedContainer = _container;
	std::sort(sortedContainer.begin(), sortedContainer.end());

	int minDiff = INT_MAX;
	for (size_t i = 0; i < sortedContainer.size() - 2; i++)
	{
		int newDiff = abs(sortedContainer[i] - sortedContainer[i + 1]);
		if (newDiff < minDiff)
			minDiff = newDiff;
	}
	return (minDiff);
}


int Span::longestSpan(void)
{
	if (_container.size() < 2)
		throw std::out_of_range("Error: Container need at least 2 elements");
	int maxElement = *std::max_element(_container.begin(), _container.end());
	int minElement = *std::min_element(_container.begin(), _container.end());
	return (maxElement - minElement);
}

Span::~Span()
{
}
