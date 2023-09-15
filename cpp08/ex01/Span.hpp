#ifndef SPAN_HPP
# define SPAN_HPP

# include <climits>
# include <vector>
# include <iostream>
# include <algorithm>

class Span
{
	public:
		Span(unsigned int N);
		Span(const Span &src);
		~Span();
		void addNumber(unsigned int new_n);
		void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan();
		int	longestSpan();

		Span &operator=(const Span &src);
	private:
		unsigned int _size;
		std::vector<int> _container;

};

#endif
