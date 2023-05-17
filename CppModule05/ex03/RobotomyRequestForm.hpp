#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    public:
        RobotomyRequestForm(std::string _target);
        RobotomyRequestForm(const RobotomyRequestForm&);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &);
        std::string getTarget() const;
        void execute(Bureaucrat const &) const;
        ~RobotomyRequestForm();
    private:
        RobotomyRequestForm();
        std::string target;
};

#endif
