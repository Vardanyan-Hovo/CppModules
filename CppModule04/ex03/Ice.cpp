#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
}

Ice::Ice(const Ice &obj) : AMateria("ice")
{
    *this = obj;
}

Ice &Ice::operator=(const Ice &obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return *this;
}

Ice::~Ice()
{

}

//-------------------------------------------------

AMateria* Ice::clone() const
{
    Ice *tmp = new Ice();
    return tmp;
}

void Ice::use(ICharacter& t)
{
    std::cout<<"* shoots an ice bolt at "<< t.getName()<<" *"<<std::endl;
}
