#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    story[0] = 0;
    story[1] = 0;
    story[2] = 0;
    story[3] = 0;
    id = 0;
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
    *this = obj;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &obj)
{
    int  i = 0;

    if (this != &obj)
    {
        while (i < obj.getId())
        {
            *(this->story[i]) = *(obj.story[i]);
            i++;
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    int i = 0;

    while (i < this->id)
    {
        delete story[i];
        i++;
    }
    
}

//--------------------------------------------

void MateriaSource::learnMateria(AMateria *a)
{
    if (!a || id == 4)
        return ;
    if (a->getType().compare("ice") == 0)
    {
        story[id] = new Ice();
        *(story[id]) = *a;
    }
    if (a->getType().compare("cure") == 0)
    {
        story[id] = new Cure();
        *(story[id]) = *a;
    }
    id++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    AMateria *tmp = 0;

    int i = 0;
    while (i < this->id)
    {
        if (this->story[i] && this->story[i]->getType().compare(type) == 0)
        {
            if (type.compare("ice") == 0)
            {
                tmp = new Ice();
            }
            if (type.compare("cure") == 0)
            {
                tmp = new Cure();
            }
            return tmp;
        }
        i++;
    }
    return tmp;
}

int MateriaSource::getId() const
{
    return id;
}
