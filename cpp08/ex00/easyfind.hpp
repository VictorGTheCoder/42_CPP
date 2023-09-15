#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>

template <typename T>
void easyfind(T &int_container, int target)
{
	if  (std::find(int_container.begin(), int_container.end(), target) != int_container.end())
	{
		std::cout << "Target found" << std::endl;
	}
	else
	{
		std::cout << "Target not found" << std::endl;
	}
}

#endif