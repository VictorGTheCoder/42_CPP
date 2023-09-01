#include "RPN.hpp"

int main(int argc, char const *argv[])
{
    (void) argc;
    (void) argv;
    std::string expression = "8 9 * 9 - 9 - 9 - 4 - 1 +";
    std::string expression1 = "7 7 * 7 -";
    std::string expression2 = "1 2 * 2 / 2 * 2 4 - +";
    std::string expression3 = "(1 + 1)";
    std::string advanced = "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /";

    RPN *rpn = new RPN(expression);
    RPN *rpn2 = new RPN(expression1);
    RPN *rpn3 = new RPN(expression2);
    RPN *rpn4 = new RPN(expression3);
    RPN *advancedrpn = new RPN(advanced);
    
    delete rpn;
    delete rpn2;
    delete rpn3;
    delete rpn4;
    delete advancedrpn;

    return 0;
}
