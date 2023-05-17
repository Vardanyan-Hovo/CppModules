
#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"


class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog &);
        Dog &operator=(const Dog &);
        ~Dog();
    public:
        void makeSound() const;
        std::string getType() const;
};

#endif
