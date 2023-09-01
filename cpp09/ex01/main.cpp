#include "RPN.hpp"

int main(int argc, char const *argv[])
{
    std::string expression = "8 9 * 9 - 9 - 9 - 4 - 1 +";
    RPN *rpn = new RPN(expression);
    return 0;
}
