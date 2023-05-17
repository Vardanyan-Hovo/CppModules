#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"


class Cat : virtual public Animal
{
    public:
        Cat();
        Cat(const Cat &);
        Cat &operator=(const Cat &);
        ~Cat();
    public:
         void makeSound() const;
         std::string getType() const;
    private:
        Brain* brain;
};

#endif