#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j;//should not create a leak
    delete i;
    // while (1){}

    j = new Dog();
    i = new Cat();
    Animal obj[2];
    std::cout<<std::endl;
    i->makeSound();
    j->makeSound();
    obj[1] = *j;

    obj[0].makeSound();
    obj[1].makeSound();
    std::cout<<std::endl;
    delete j;
    delete i;

    return 0;
}
