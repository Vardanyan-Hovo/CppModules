
#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"


class Dog : public virtual Animal
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