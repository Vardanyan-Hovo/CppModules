#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    std::cout<<"WrongCat and WrongAnimal class"<<std::endl<<std::endl;

    WrongAnimal* wrongmeta = new WrongAnimal();
    WrongAnimal* wronj = new WrongCat();
    wrongmeta->makeSound();
    wronj->makeSound();
    wronj->makeSound();

    delete wrongmeta;
    delete wronj;
    delete meta;
    delete j;
    delete i;
    return 0;
}
