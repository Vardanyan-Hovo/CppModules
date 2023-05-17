#include "Dog.hpp"

Dog::Dog()
{
    std::cout<<"Dog Default constructor call"<<std::endl;
    this->type = "Dog";
}

Dog::Dog(const Dog &obj)
{
    std::cout<<"Dog copy constructor call"<<std::endl;
    *this = obj;
}

Dog &Dog::operator=(const Dog &obj)
{
    std::cout<<"Dog assigment operator call"<<std::endl;
    if (this == &obj)
        return *this;
    this->type = obj.type;
    return *this;
}

Dog::~Dog()
{
    std::cout<<"Dog Destructor call"<<std::endl;
}

void Dog::makeSound() const
{
    std::cout<<"Dog bark"<<std::endl;
}


std::string Dog::getType() const
{
    return type;
}
