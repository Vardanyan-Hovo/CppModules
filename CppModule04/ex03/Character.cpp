#include "Character.hpp"

Character::Character()
{
    this->name = "character";
    idx = 0;
    slot[0] = 0;
    slot[1] = 0;
    slot[2] = 0;
    slot[3] = 0;
}

Character::Character(const std::string &name)
{
    this->name = name;
    idx = 0;
    slot[0] = 0;
    slot[1] = 0;
    slot[2] = 0;
    slot[3] = 0;
}

//  Any copy
// (using copy constructor or copy assignment operator) of a Character must be deep.
Character::Character(const Character &obj)
{
    *this = obj;
}

//  Any copy(using copy constructor or copy assignment operator) of a Character must be deep.
// During copy, the Materias of a Character must be deleted before the new ones are added


Character &Character::operator=(const Character &obj)
{
    int i = 0;

    if (this != &obj)
    {
        while (i < 4)
        {
            delete this->slot[i];
            this->slot[i] = 0;
            i++;
        }
        i = 0;        
        this->name = obj.name;
        while (i < obj.getIdIndex())
        {
            if ( obj.slot[i]->getType().compare("ice") == 0)
                this->slot[i] = new Ice();
            if (obj.slot[i]->getType().compare("Cure") == 0)
                this->slot[i] = new Cure();
            *(this->slot[i]) = *(obj.slot[i]);
            i++;
        }
        this->idx = obj.getIdIndex();
    }
    return *this;
}

// Of course, the Materias must be deleted when a Character is destroyed.
Character::~Character()
{
    for(int i = 0; i < this->idx; i++)
    {
        delete this->slot[i];
    }
}

//----------------------------------------------

std::string const & Character::getName() const
{
    return this->name;
}

void Character::equip(AMateria* m)
{
    if (m && idx < 4)
    {
        if (m->getType().compare("ice") == 0)
            this->slot[idx] = new Ice();
        else if (m->getType().compare("cure") == 0)
            this->slot[idx] = new Cure();
        else
            return ;
        *(this->slot[idx]) = *m;
        idx++;
    }
}
void Character::unequip(int idx)
{
    if (idx < this->idx && idx >= 0)
    {
        delete this->slot[idx];
        while (idx + 1 < this->idx)
        {
            this->slot[idx] = this->slot[idx + 1];
            idx++;
        }
        this->slot[idx] = 0;
        this->idx--;
    }
}
// The use(int, ICharacter&) member function will have to use the Materia at the
// slot[idx], and pass the target parameter to the AMateria::use function.
//   virtual void use(ICharacter& target);
void Character::use(int idx, ICharacter& target)
{
    if(idx < this->idx && idx >= 0)
    {
        this->slot[idx]->use(target);
    }
}

int Character::getIdIndex() const
{
    return idx;
}
