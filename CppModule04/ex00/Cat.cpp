#include "Cat.hpp"

Cat::Cat()
{
    std::cout<<"Cat Default constructor call"<<std::endl;
    this->type = "Cat";
}

Cat::Cat(const Cat &obj)
{
    std::cout<<"Cat copy constructor call"<<std::endl;
    *this = obj;
}

Cat &Cat::operator=(const Cat &obj)
{
    std::cout<<"Cat assigment operator call"<<std::endl;
    if (this == &obj)
        return *this;
    this->type = obj.type;
    return *this;
}

Cat::~Cat()
{
    std::cout<<"Cat Destructor call"<<std::endl;
}


void Cat::makeSound() const
{
    std::cout<<"Cat meow"<<std::endl;
}

std::string Cat::getType() const
{
    return type;
}
