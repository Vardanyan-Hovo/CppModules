#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm():AForm( "PresidentialPardonForm", 25, 5),target("Bureaucrat default")
{

}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &obj):AForm( "PresidentialPardonForm", 25, 5),target(obj.target)
{

}
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &obj)
{
    if (this != &obj)
    {
        this->target = obj.target;
    }
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm( "PresidentialPardonForm", 25, 5),target(target)
{
}

std::string PresidentialPardonForm::getTarget()
{
    return target;
}
void PresidentialPardonForm::execute(Bureaucrat const &b) const
{
    if (!this->getIfsign())
        throw AForm::GradeTooLowException("PresidentialPardonForm: Bureaucrat is not sign in");
    if (b.getGrade() > this->getExec())
    {
        throw AForm::GradeTooLowException("PresidentialPardonForm: Bureaucrat grade small exec");
    }
    info();
}

void PresidentialPardonForm::info() const
{
    std::cout<<target<< "has been pardoned by Zaphod Beeblebrox"<<std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}
