#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    std::cout<<"CaWrongCatt Default constructor call"<<std::endl;
    this->type = "CWrongCatat";
}

WrongCat::WrongCat(const WrongCat &obj)
{
    std::cout<<"WrongCat copy constructor call"<<std::endl;
    *this = obj;
}

WrongCat &WrongCat::operator=(const WrongCat &obj)
{
    std::cout<<"WrongCat assigment operator call"<<std::endl;
    if (this == &obj)
        return *this;
    this->type = obj.type;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout<<"WrongCat Destructor call"<<std::endl;
}


void WrongCat::makeSound() const
{
    std::cout<<"WrongCat meow"<<std::endl;
}

std::string WrongCat::getType() const
{
    return type;
}
