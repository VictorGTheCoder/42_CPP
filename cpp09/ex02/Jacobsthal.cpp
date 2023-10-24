#include <vector>

// Function to generate Jacobsthal numbers
int jacobsthal(int n)
{
    if (n == 0) return 1;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

// Function to generate the first n Jacobsthal numbers and store them in a vector
std::vector<int> generateJacobsthalNumbers(int n)
{
    std::vector<int> numbers;
    for(int i = 0; i < n; ++i) {
        numbers.push_back(jacobsthal(i));
    }
    return numbers;
}


