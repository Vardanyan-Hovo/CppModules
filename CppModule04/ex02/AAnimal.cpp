#include "AAnimal.hpp"

AAnimal::AAnimal()
{
    std::cout<<"Animal Default constructor call"<<std::endl;
    this->type = "AAnimal";
}

AAnimal::AAnimal(const AAnimal &obj)
{
    std::cout<<"Animal copy constructor call"<<std::endl;
    *this = obj;
}

AAnimal &AAnimal::operator=(const AAnimal &obj)
{
    std::cout<<"Animal assigment operator call"<<std::endl;
    if (this == &obj)
        return *this;
    this->type = obj.type;
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout<<"Animal Destructor call"<<std::endl;
}


std::string AAnimal::getType() const
{
    return type;
}

void AAnimal::setType(const std::string &name)
{
    this->type = name;
}
