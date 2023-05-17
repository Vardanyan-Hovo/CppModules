#include "Form.hpp"

int main()
{
    try {
        Form *F  = new Form("Form Intern:",100);
        Bureaucrat *B = new Bureaucrat(140, "Bur");
        Bureaucrat *B1 = new Bureaucrat(70, "Bur2");
        B->signForm(*F);
        B1->signForm(*F);
        delete F;
        delete B;
        delete B1;
    }
    catch(std::exception &e)
    {
        std::cout<<e.what();
    }
    std::cout<<std::endl;
    try {
        Bureaucrat *B = new Bureaucrat(60, "Bur");
        Form *F  = new Form("Form Intern", 50);
        B->signForm(*F);
        F->beSigned(*B);
        delete F;
        delete B;
    }
    catch(std::exception &e)
    {
        std::cout<<e.what()<<std::endl;
    }
    return 0;
}
