#ifndef FORM
# define FORM

#include <iostream>

class Form
{
private:
    const std::string _name;
    bool   _signed;
    const int _grade;   
public:
    Form();
    ~Form();
};

Form::Form()
{
}

Form::~Form()
{
}

#endif