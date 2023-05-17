#include "AForm.hpp"

AForm::AForm(const std::string &_name, int const &_sign, const int &_exec):name(_name),sign(_sign),exec(_exec)
{
    this->ifsign = false;
    checkSign(_sign);
    checkSign(_exec);
}
AForm::AForm():name("AForm"),ifsign(false), sign(150), exec(150)
{

}
AForm::AForm(const AForm &obj):name(obj.getName()),ifsign(obj.getIfsign()), sign(obj.getSign()), exec(obj.getExec())
{
}
AForm &AForm::operator=(const AForm &obj)
{
    if (this != &obj)
    {
        ifsign = obj.getIfsign();
    }
    return *this;
}
const char * AForm::GradeTooHighException::what() const throw()
{
    return "Form Grade Too High Exception";
}

AForm::GradeTooLowException::GradeTooLowException(const char *reason) : s(reason)
{
}

AForm::GradeTooLowException::GradeTooLowException():s("Grade Too Low Exception")
{
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return s;
}

std::string AForm::getName() const
{
    return this->name;
}

bool AForm::getIfsign() const
{
    return this->ifsign;
}

int AForm::getSign() const
{
    return this->sign;
}

int AForm::getExec() const
{
    return exec;
}

void AForm::checkSign(int x)
{
    if (x < 1)
	{
		throw AForm::GradeTooHighException();
	} else if (x > 150)
	{
		throw AForm::GradeTooLowException();
	}
}

void AForm::beSigned(Bureaucrat &b)
{
    if (this->sign >= b.getGrade())
        this->ifsign = true;
    else
       throw AForm::GradeTooLowException("Bureaucrat is not sign in");
}

AForm::~AForm()
{
}

std::ostream & operator<<(std::ostream &ost, AForm &f)
{
   ost<<"name            = "<<f.getName()<<std::endl;
   ost<<"is signed       = "<<(f.getIfsign() ? "True": "False")<<std::endl;
   ost<<"grade required  = " <<f.getSign()<<std::endl;
   ost<<"grade execute   = "<<f.getExec()<<std::endl;
   return ost;
}
