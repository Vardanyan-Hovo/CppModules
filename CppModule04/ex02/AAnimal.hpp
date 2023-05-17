#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
    public:
        AAnimal();
        AAnimal(const AAnimal &);
        AAnimal &operator=(const AAnimal &);
        virtual ~AAnimal();
    public:
        void virtual makeSound() const = 0;
        std::string getType() const;
        void setType(const std::string &);

    protected:
         std::string type;
};

#endif
