#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"


class WrongCat : virtual public WrongAnimal
{
    public:
        WrongCat();
        WrongCat(const WrongCat &);
        WrongCat &operator=(const WrongCat &);
        ~WrongCat();
    public:
        std::string getType() const;
        void makeSound() const;
};

#endif
