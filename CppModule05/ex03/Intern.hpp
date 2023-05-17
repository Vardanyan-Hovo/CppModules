#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

class Intern
{
    public:
        Intern();
        Intern(const Intern &);
        Intern operator=(const Intern &);
        AForm *makeForm(std::string form, std::string byurokrat);
        AForm *ShrubberyCreation(const std::string target);
        AForm *RobotomyRequest(const std::string target);
        AForm *PresidentialPardon(const std::string target);
        ~Intern();       
};

#endif
