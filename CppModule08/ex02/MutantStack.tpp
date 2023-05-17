#include "MutantStack.hpp"

template <class T , class Container>
Container MutantStack<T, Container>::getC()
{
    return (this->c);
}

template <class T , class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
    return this->c.begin();
};

template <class T , class Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
    return this->c.end();
}
