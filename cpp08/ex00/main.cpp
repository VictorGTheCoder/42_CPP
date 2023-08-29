#include "easyfind.hpp"

#include <vector>


int main()
{
	int arr[] = {5, 10, 15, 20, 25, 30};
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));

	easyfind(vec, 1);	
	easyfind(vec, 10);


	return 0;
}
