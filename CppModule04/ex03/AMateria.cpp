#include "AMateria.hpp"

AMateria::AMateria(std::string const & type)
{
    this->type = type;
}

std::string const & AMateria::getType() const //Returns the materia type
{
    return type;
}

// virtual AMateria* clone() const = 0;
void AMateria::use(ICharacter& target)
{
    std::cout<<" Definition use  "<<target.getName()<<std::endl;
}

AMateria::~AMateria()
{
    
}
