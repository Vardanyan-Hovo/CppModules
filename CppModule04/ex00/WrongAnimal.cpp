#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout<<"WrongAnimal Default constructor call"<<std::endl;
    this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
    std::cout<<"WrongAnimal copy constructor call"<<std::endl;
    *this = obj;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
    std::cout<<"WrongAnimal assigment operator call"<<std::endl;
    if (this == &obj)
        return *this;
    this->type = obj.type;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout<<"WrongAnimal Destructor call"<<std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout<<"WrongAnimal growl"<<std::endl;
}


std::string WrongAnimal::getType() const
{
    return type;
}
