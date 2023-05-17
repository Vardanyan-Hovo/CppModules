#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(const Cure&);
        Cure &operator=(const Cure &);
        ~Cure();
    public:
        AMateria* clone() const;
        void use(ICharacter& t);
};

#endif
