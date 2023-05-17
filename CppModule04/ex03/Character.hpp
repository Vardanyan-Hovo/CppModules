#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>
#include <string>
#include "ICharacter.hpp"



class Character : public ICharacter
{
    public:
        Character();
        Character(const std::string &);
        Character(const Character&);
        Character &operator=(const Character&);
        ~Character();
    public:
        std::string const & getName() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        int getIdIndex() const;
    private:
        int idx;
        std::string name;
        AMateria *slot[4];
};

#endif
