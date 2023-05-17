#include "RobotomyRequestForm.hpp"


RobotomyRequestForm::RobotomyRequestForm(std::string _target) : AForm("RobotomyRequestForm",72, 45),target(_target)
{
}

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm",72, 45),target("Robot default")
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm&obj): AForm("RobotomyRequestForm",72, 45),target(obj.getTarget())
{

}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &obj)
{
    if (this !=&obj)
    {
        this->target = obj.getTarget();
    }
    return *this;
}
std::string RobotomyRequestForm::getTarget() const
{
    return target;
}

void RobotomyRequestForm::execute(Bureaucrat const &b) const
{
    if (!this->getIfsign())
        throw AForm::GradeTooLowException("RobotomyRequestForm: failed :Bureaucrat is not sign in");
    if (b.getGrade() > this->getExec())
    {
        throw AForm::GradeTooLowException("RobotomyRequestForm: failed :Bureaucrat grade small exec");
    }
    std::cout<< target << " robotomized successfully 50\% Of the time "<<std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}