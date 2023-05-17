
#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"


class Dog : public virtual AAnimal
{
    public:
        Dog();
        Dog(const Dog &);
        Dog &operator=(const Dog &);
        ~Dog();
    public:
         void makeSound() const;
         std::string getType() const;
    private:
        Brain* brain;
};

#endif