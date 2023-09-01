#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include <stack>

class RPN
{
    public:
        RPN();
        RPN(std::string exp);
        RPN(RPN &r);
        ~RPN();

        void Parse(std::string exp);
    private:
        std::string _exp;
        std::stack<char> _op;
        std::stack<int> _nb;

    RPN &operator=(RPN &r);
};


#endif