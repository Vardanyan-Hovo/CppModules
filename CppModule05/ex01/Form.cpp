#include "Form.hpp"

Form::Form():name("FORM"), sign(false), grade(150), execute(150)
{
}

Form::Form(const std::string &_name, int grad) : name(_name),sign(false),grade(grad),execute(150)
{
    checkGrade(grad);
}

Form::Form(const Form &f) : name(f.getName()), sign(f.getSign()), grade(f.getGrade()), execute(f.getExecute())
{
    checkGrade(grade);
}

Form &Form::operator=(const Form &f)
{
    if (this != &f)
    {
        // this->name = f.getName;
        this->sign = f.getSign();
        // this->grade = f.getGrade();
        // this->execute = f.getExecute();
    }
    return *this; 
}

Form::~Form()
{
}

std::string Form::getName() const
{
    return this->name;
}

bool Form::getSign() const
{
    return this->sign;
}

int Form::getGrade() const
{
    return this->grade;
}

int Form::getExecute() const
{
    return this->execute;
}

void Form::checkGrade(int x)
{
    if (x < 1)
	{
		throw Form::GradeTooHighException();
	} else if (x > 150)
	{
		throw Form::GradeTooLowException();
	}
}

void Form::beSigned(Bureaucrat &b)
{
    if (this->grade >= b.getGrade())
        this->sign = true;
    else
    {
        this->sign = false;
        throw Form::GradeTooLowException();
    }
}

const char *Form::GradeTooHighException::what() const throw()
{
    return "Form Grade Too Low Exception";
}

const char *Form::GradeTooLowException::what() const throw()
{
    return "Form Grade Too Low Exception";
}

std::ostream & operator<<(std::ostream &ost, Form &f)
{
   ost<<"name ="<<f.getName()<<" is signed ="<< f.getSign();
   ost<<"  grade required " <<f.getGrade()<<" grade execute = "<<f.getExecute()<<std::endl;
   return ost;
}
