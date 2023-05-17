#include "Animal.hpp"

Animal::Animal()
{
    std::cout<<"Animal Default constructor call"<<std::endl;
    this->type = "Animal";
}

Animal::Animal(const Animal &obj)
{
    std::cout<<"Animal copy constructor call"<<std::endl;
    *this = obj;
}

Animal &Animal::operator=(const Animal &obj)
{
    std::cout<<"Animal assigment operator call"<<std::endl;
    if (this == &obj)
        return *this;
    this->type = obj.type;
    return *this;
}

Animal::~Animal()
{
    std::cout<<"Animal Destructor call"<<std::endl;
}

void Animal::makeSound() const
{
    std::cout<<"Animal growl"<<std::endl;
}


std::string Animal::getType() const
{
    return type;
}
