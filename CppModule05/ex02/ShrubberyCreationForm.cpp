#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137),target(target)
{
}


ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm",72, 45),target("Robot default")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm&obj): AForm("ShrubberyCreationForm",72, 45),target(obj.getTarget())
{

}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
    if (this !=&obj)
    {
        this->target = obj.getTarget();
    }
    return *this;
}

std::string ShrubberyCreationForm::getTarget() const
{
    return target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &b) const 
{
    if (!this->getIfsign())
        throw AForm::GradeTooLowException("ShrubberyCreationForm: Bureaucrat is not sign in");
    if (b.getGrade() > this->getExec())
    {
        throw AForm::GradeTooLowException("ShrubberyCreationForm: Bureaucrat grade small exec");
    }
    createFile(target);
}

void ShrubberyCreationForm::createFile(std::string target) const
{
    std::ofstream ost;
    ost.open(target + "_shrubbery", std::ios::out);
    
if (ost.is_open())
{
 ost<<  "         /\\         " <<std::endl; 
 ost<<  "        /\\*\\        " <<std::endl; 
 ost<<  "       /\\O\\*\\       " <<std::endl; 
 ost<<  "      /*/\\/\\/\\      " <<std::endl; 
 ost<<  "     /\\O\\/\\*\\/\\     " <<std::endl; 
 ost<<  "    /\\*\\/\\*\\/\\/\\    " <<std::endl; 
 ost<<  "   /\\O\\/\\/*/\\/O/\\   " <<std::endl; 
 ost<<  "         ||         " <<std::endl; 
 ost<<  "         ||         " <<std::endl; 
 ost<<  "         ||         " <<std::endl;
    ost.close();
}

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}
