#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &);
        WrongAnimal &operator=(const WrongAnimal &);
        virtual ~WrongAnimal();
    public:
        void makeSound() const;
    protected:
        std::string type;
        std::string getType() const;
};

#endif
