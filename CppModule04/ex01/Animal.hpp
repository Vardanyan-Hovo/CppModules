#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
    public:
        Animal();
        Animal(const Animal &);
        Animal &operator=(const Animal &);
        virtual ~Animal();
    public:
        void virtual makeSound() const;
        std::string getType() const;
        void setType(const std::string &);

    protected:
         std::string type;
};

#endif