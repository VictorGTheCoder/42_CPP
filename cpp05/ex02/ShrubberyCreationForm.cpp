#include "ShrubberyCreationForm.hpp"
#include <fstream> 

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery Creation Form", 145, 137)
{
	setTarget("target");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation Form", 145, 137)
{
	setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &f) : AForm(f)
{
	setTarget(f.getTarget());
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (isSigned() == false)
        throw FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
    	throw GradeTooLowException();
    std::string fName = (getTarget() + "_shrubbery");
    std::ofstream myFile(fName.c_str());
    myFile << getTarget() << "\n     oxoxoo    ooxoo\n  ooxoxo oo  oxoxooo \n oooo xxoxoo ooo ooox\n oxo o oxoxo  xoxxoxo\n  oxo xooxoooo o ooo\n    ooo\\oo\\  /o/o\n        \\  \\/ /\n         |   /\n         |  |\n         | D|\n         |  |\n         |  |\n  ______/____\\____"<< std::endl;
    myFile.close();
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &f)
{
    if (this != &f) {
        AForm::operator=(f);
    }
    return *this;
}
