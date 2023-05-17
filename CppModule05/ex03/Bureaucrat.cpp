#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():name("Bureaucrat"),grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string &name):name(name), grade(150)
{
}

Bureaucrat::Bureaucrat(const int &i, const std::string &name):name(name)
{
	CheckException(i);
	this->grade = i;
}

Bureaucrat::Bureaucrat(const Bureaucrat &obj) : name(obj.getName()),grade(obj.getGrade())
{
	CheckException(obj.getGrade());
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &obj)
{
	if (this != &obj)
	{
		// this->name = obj.getName();
		this->grade = obj.getGrade();
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
}

void Bureaucrat::CheckException(int i)
{
	if (i < 1)
	{
		throw Bureaucrat::GradeTooHighException();
	}
	else if (i > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
}

// means less than 1
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade Too High Exception";
}

//means more than 150
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade Too Low Exception";
}

std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

//----------------------------------------- highest possible grade 1
int Bureaucrat::operator++(int)
{
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
	return this->grade + 1;
}

int Bureaucrat::operator++(void)
{
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
	return this->grade;
}

int Bureaucrat::increment(void)
{
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
	return this->grade;
}

//----------------------------------------lowest possible grade 150
int Bureaucrat::operator--(int)
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
	return this->grade - 1;
}

int Bureaucrat::operator--(void)
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
	return this->grade;
}

int Bureaucrat::decrement(void)
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
	return this->grade;
}

void Bureaucrat::signForm(AForm &b)
{
	try {
		b.beSigned(*this);
		std::cout<<b.getName()<<" signed "<<this->name<<std::endl;
	}
	catch (std::exception & e){
		std::cout<<b.getName()<<"  couldn't sign "<< this->getName();
        std::cout<<" because "<< e.what() <<std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
        form.execute(*this);
		std::cout<<this->getName()<<" executed "<<form.getName()<<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
}


//<name>, bureaucrat grade <grade>.
std::ostream& operator<<(std::ostream &f, Bureaucrat &b)
{
	f<<b.getName();
	f<<", bureaucrat grade ";
	f<<b.getGrade()<<std::endl;
	return f;
}
