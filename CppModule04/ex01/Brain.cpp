#include "Brain.hpp"

Brain::Brain()
{
    std::cout<<"Brain Default constructor call"<<std::endl;
}

Brain::Brain(const Brain &obj)
{
    std::cout<<"Brain copy constructor call"<<std::endl;
    *this = obj;
}

Brain &Brain::operator=(const Brain &obj)
{
     std::cout<<"Brain assigment operator call"<<std::endl;
    if (this != &obj)
    {
        for(int i = 0; i < 100; i++)
            this->ideas[i] = obj.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout<<"Brain Destructor call"<<std::endl;
}

