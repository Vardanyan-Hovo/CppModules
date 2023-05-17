#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

class MateriaSource : public IMateriaSource
{
    public:
        MateriaSource();
        MateriaSource(const MateriaSource&);
        MateriaSource &operator=(const MateriaSource &);
        ~MateriaSource();
    public:
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
        int getId() const;
    private:
        AMateria* story[4];
        int id;
};

#endif
