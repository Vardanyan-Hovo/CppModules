#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook
{
    public:
        PhoneBook();
        ~PhoneBook();

    public:
        void ADD(Contact NewContact);
        void SEARCH(int index);
        void EXIT();
        void call_revers();
        void All();

    private:
        Contact contacts[8];
        static size_t size;
};

#endif