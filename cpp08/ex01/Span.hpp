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
		~Span();
		void addNumber(unsigned int new_n);
		int shortestSpan();
		int	longestSpan();
	private:
		unsigned int _size;
		std::vector<int> _container;
};

#endif
