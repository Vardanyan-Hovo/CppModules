#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>
#include <string>

class Bureaucrat;
class ShrubberyCreationForm;
class AForm
{
    public:
        AForm(const std::string &_name, int const &_sign, int const &_exec);
        virtual ~AForm();
    public:
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                GradeTooLowException();
                GradeTooLowException(const char *s);
                virtual const char *what() const throw();
            private:
                const char *s;
        };
        std::string getName() const;
        bool getIfsign() const;
        int getSign() const;
        int getExec() const;
        void checkSign(int );
		void beSigned(Bureaucrat &);
        virtual void execute(Bureaucrat const & executor) const = 0;
    private:
        const std::string name;
        bool ifsign;            //A boolean indicating whether it is signed
        const int sign;         //A constant grade required to sign it.
        const int exec;
        
};

std::ostream& operator<<(std::ostream &, AForm &);

#endif
