#include "RPN.hpp"

void RPN::Parse(std::string exp)
{
    std::stringstream input_stringstream(exp);
    std::string arg;
    while (getline(input_stringstream,arg,' '))
    {
       if (arg == "+" || arg == "-" || arg == "*" || arg == "/")
       {
            if (s.size() > 1)
            {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                if (arg == "+")
                    s.push(a + b);
                if (arg == "-")
                    s.push(a - b);
                if (arg == "*")
                    s.push(a * b);
                if (arg == "/")
                {
                    if (b == 0)
                    {
                        throw std::runtime_error("Error dividing by '0'");
                    }
                    else
                        s.push(a / b);
                }
            }
       }
       else if (arg.size() == 1 && std::isdigit(arg[0]))
       {
            s.push((int) (std::atoi(arg.c_str())));
       }
       else
       {
            throw std::runtime_error("Expression cannot be compute");
       }
    }
    if (s.size())
        std::cout << s.top() << std::endl;
}

RPN::RPN()
{
}

RPN::RPN(const RPN &r)
{
    *this = r;
}

RPN::RPN(std::string exp)
{
    try
    {
        Parse(exp);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

}

RPN::~RPN()
{
    
}

RPN& RPN::operator=(const RPN& r)
{
    this->s = r.s;
    return *this;
}