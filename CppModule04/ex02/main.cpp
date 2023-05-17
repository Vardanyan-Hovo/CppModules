#include "Cat.hpp"
#include "Dog.hpp"
#include  "AAnimal.hpp"

int main()
{
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();
    AAnimal *obj[2];
    // AAnimal obj[2]; you cannot create an instance of an abstract class
    // obj[0] = Cat();copy
    // obj[1] = Dog();copy
    obj[0] = new Dog();
    obj[1] = new Cat();
    obj[0]->makeSound();

    delete j;
    delete i;

    return 0;
}
