#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : virtual public AMateria
{
    public:
        Ice();
        Ice(const Ice&);
        Ice &operator=(const Ice&);
        ~Ice();
    public:
        AMateria* clone() const;
        void use(ICharacter& t);
};

#endif
