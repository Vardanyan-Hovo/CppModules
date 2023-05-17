#include <iostream>
#include "PhoneBook.hpp"


PhoneBook::PhoneBook()
{
    for (int i = 0; i < 8; i++)
        this->contacts[i].Setindex(i);
}

PhoneBook::~PhoneBook()
{
}

void    PhoneBook::All()
{
    size_t n;

    if (PhoneBook::size)
    {
        n = PhoneBook::size;
        if (PhoneBook::size == 7)
            n++;
        for (size_t i = 0; i < n; i++)
            contacts[i].printcontact();
    }
    else
        std::cout<<"Not contact\n";
}


void	PhoneBook::ADD(Contact NewContact)
{
	if (PhoneBook::size == 7)
	{
        PhoneBook::call_revers();
	}
    this->contacts[PhoneBook::size].SetArgments(NewContact, PhoneBook::size);
    if (PhoneBook::size == 7)
		PhoneBook::size--;
	PhoneBook::size++;
}


void PhoneBook::SEARCH(int index)
{
    if (index >= 0 && index <= 7 && (size_t)index < PhoneBook::size && PhoneBook::size != 0)
        contacts[index].printcontact();
    else
        std::cout<<"Contact not found"<<std::endl;
}

void PhoneBook::call_revers()
{
    for (size_t i = 0; i < 7; i++)
    {
        this->contacts[i] = this->contacts[i + 1];
        this->contacts[i].Setindex(i);
    }
}

void PhoneBook::EXIT()
{
    std::cout<<"EXIT"<<std::endl;
    std::exit(0);
}

size_t PhoneBook::size = 0;