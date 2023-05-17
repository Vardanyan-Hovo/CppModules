#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    public:
        PresidentialPardonForm(std::string _name);
        PresidentialPardonForm(const PresidentialPardonForm &);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &);
        std::string getTarget();
        void info() const;
        void execute(Bureaucrat const &) const;
        ~PresidentialPardonForm();
    private:
        PresidentialPardonForm();
        std::string target;
};

#endif
