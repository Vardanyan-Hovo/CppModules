#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &obj)
{
    (void)obj;
}
Intern Intern::operator=(const Intern &obj)
{
    (void)obj;
    return *this;
}

AForm *Intern::ShrubberyCreation(const std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::RobotomyRequest(const std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm *Intern::PresidentialPardon(const std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string form, std::string byurokrat)
{
    typedef AForm* (Intern::*Func)(std::string);
    Func f[] = {&Intern::RobotomyRequest,&Intern::ShrubberyCreation, &Intern::PresidentialPardon};
    std::string s[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};//"robotomy request"
    int i = 0;

    while (i < 3 && s[i] != form)
        i++;
    if (i < 3)
        return ((this->*f[i])(byurokrat));
    std::cout<< "Intern creates " + form<<std::endl;
    return NULL;
}

Intern::~Intern()
{
}
