#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>
#include <string>

class Bureaucrat;

class Form
{
    public:
        Form();
        Form(const std::string &, int);
        Form(const Form &);
        Form &operator=(const Form &);
        ~Form();
    public:
        struct GradeTooHighException : std::exception
        {
            public:
                const char *what() const throw();
        };
        struct GradeTooLowException : std::exception
        {
            public:
                const char *what() const throw();
        };
        std::string getName() const;
        bool getSign() const;
        int getGrade() const;
        int getExecute() const;
        void checkGrade(int );
		void beSigned(Bureaucrat &);
    private:
        const std::string name;
        bool sign;            //A boolean indicating whether it is signed
        const int grade;        //A constant grade required to sign it.
        const int execute;
        
};

std::ostream& operator<<(std::ostream &, Form &);

#endif
