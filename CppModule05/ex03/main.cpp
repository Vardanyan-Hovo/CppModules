#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
    Intern someRandomIntern;
    AForm* rrf;
    AForm* rrfbad;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    rrfbad = someRandomIntern.makeForm("presidential ", "BenderBAD");
    if (rrf)
        std::cout<<rrf->getName()<<std::endl;
    if (rrfbad)
        std::cout<<rrfbad->getName()<<std::endl;
    delete rrf;
    delete rrfbad;
    return 0;
}
