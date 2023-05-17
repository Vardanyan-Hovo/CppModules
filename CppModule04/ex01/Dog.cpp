#include "Dog.hpp"

Dog::Dog()
{
    std::cout<<"Dog Default constructor call"<<std::endl;
    this->type = "Dog";
    this->brain = new Brain();
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
    this->brain = new Brain();
    *(this->brain) = *(obj.brain);
    return *this;
}

Dog::~Dog()
{
    delete brain;
    std::cout<<"Dog Destructor call"<<std::endl;
}

std::string Dog::getType() const
{
    return type;
}

void Dog::makeSound() const
{
    std::cout<<"Dog bark"<<std::endl;
}
