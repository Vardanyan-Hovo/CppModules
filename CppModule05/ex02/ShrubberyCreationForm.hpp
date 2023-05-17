#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    public:
        ShrubberyCreationForm(std::string _name);
        ShrubberyCreationForm(const ShrubberyCreationForm&);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
        std::string getTarget() const;
        void createFile(std::string target) const;
        void execute(Bureaucrat const &) const;
        ~ShrubberyCreationForm();
    private:
        ShrubberyCreationForm();
        std::string target;
};

#endif
