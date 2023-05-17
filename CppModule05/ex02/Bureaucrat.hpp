#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <ostream>
#include <string>
#include "AForm.hpp"


class AForm;

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
			virtual const char* what() const throw();
		};
		struct GradeTooLowException : std::exception
		{
			virtual const char* what() const throw();
		};
		std::string getName() const;
		int getGrade() const;
		int operator++(void);//throw as constructor
		int increment(void);
		int operator++(int);
		int operator--(void);//throw
		int operator--(int);
		int decrement(void);
		void CheckException(int i);
		void signForm(AForm &b);
		void executeForm(AForm const & form);
	private:
		const std::string name;
		int grade;
};

std::ostream& operator<<(std::ostream &, Bureaucrat &);

#endif
