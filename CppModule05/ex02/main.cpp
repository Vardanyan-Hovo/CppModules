#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try {
        Bureaucrat *B = new Bureaucrat(60, "Bur");
        AForm *F  = new ShrubberyCreationForm("Shrubbery");
        std::cout<<*F;
        std::cout<<*B;
        B->signForm(*F);
        F->execute(*B);
        delete F;
        delete B;
    }
    catch(std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
    try {
        Bureaucrat *B = new Bureaucrat(60, "Charles_BAD");
        Bureaucrat *BS = new Bureaucrat(40, "Charles");
        AForm *F  = new RobotomyRequestForm("ROBOT");
        std::cout<<*F;
        std::cout<<*B;
        B->signForm(*F);
        BS->signForm(*F);
        F->execute(*BS);
        F->execute(*B);
        delete F;
        delete BS;
        delete B;
    }
    catch(std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
    try {
        AForm *F  = new PresidentialPardonForm("Form Intern:");
        Bureaucrat *B = new Bureaucrat(146, "Bur");
        Bureaucrat *B1 = new Bureaucrat(140, "Bur2");
        B->signForm(*F);
        std::cout<<*F;
        std::cout<<*B;
        B1->signForm(*F);
        F->execute(*B1);
    }
    catch(std::exception &e)
    {
        std::cout<<e.what();
    }
    std::cout<<std::endl;
    std::cout<<std::endl;
    try {
        AForm *F  = new PresidentialPardonForm("Form Intern:");
        Bureaucrat *B1 = new Bureaucrat(100, "Bur2");
        std::cout<<*F;
        std::cout<<*B1;
        B1->signForm(*F);
        F->execute(*B1);
    }
    catch(std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }
    std::cout<<std::endl<<std::endl;
    std::string s = "Bur2";
    try {
        AForm *FS  = new PresidentialPardonForm("Form Intern:");
        Bureaucrat *B1 = new Bureaucrat(100, s);
        
        B1->executeForm(*FS);
        delete FS;
        delete B1;
    }
    catch(std::exception &e) {
        std::cout<< s <<"  executed "<<e.what()<<std::endl;
    }
    return 0;
}
