#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <ostream>
#include <string>
#include "Form.hpp"


class Form;

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const std::string &);
		Bureaucrat(const int &,const std::string &);
		Bureaucrat(const Bureaucrat &);
		Bureaucrat & operator=(const Bureaucrat &);
		~Bureaucrat();
	public:
		struct GradeTooHighException : std::exception
		{
			const char* what() const throw();
		};
		struct GradeTooLowException : std::exception
		{
			const char* what() const throw();
		};
		std::string getName() const;
		int getGrade() const;
		int operator++(void);//throw as constructor
		int increment(void);
		int operator++(int);
		int operator--(void);//throw
		int operator--(int);
		int decrement(void);
		int CheckException(int i);
		void signForm(Form &b);
	private:
		const std::string name;
		int grade;
};

std::ostream& operator<<(std::ostream &, Bureaucrat &);

#endif
