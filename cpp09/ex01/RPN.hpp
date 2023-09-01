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
        RPN(const RPN &r);
        ~RPN();
        RPN &operator=(const RPN &r);
        void Parse(std::string exp);
    private:
        std::stack<int> s;    
};


#endif