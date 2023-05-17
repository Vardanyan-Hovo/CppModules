#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{

}

Cure::Cure(const Cure &obj) : AMateria("cure")
{
    *this = obj;
}

Cure &Cure::operator=(const Cure &obj)
{
    if (this != &obj)
    {
        this->type = obj.type;
    }
    return *this;
}

Cure::~Cure()
{

}

//-------------------------------------------------

AMateria* Cure::clone() const
{
    Cure *tmp = new Cure();
    return tmp;
}

void Cure::use(ICharacter& t)
{
    std::cout<<"* heals "<<t.getName()<<"'s wounds *"<<std::endl;
}
