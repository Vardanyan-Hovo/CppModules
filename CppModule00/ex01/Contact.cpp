#include <iostream>
#include "Contact.hpp"

int static	srch_error1(std::string index_str)
{
	int i = 0;

    if (index_str[i] == '+')
        i++;
	while (index_str[i])
	{
		if (!(index_str[i] >= 48 && index_str[i] <= 57))
			return (-1);
        i++;
	}
	return (0);
}

Contact::Contact()
{
    this->index = 0;
    this->PhoneNumber.resize(0);
}

void    Contact::SetArgments(Contact count, int i)
{
    this->index = i;
    this->firstname = count.firstname;
    this->LastName = count.LastName;
    this->NickName = count.NickName;
    this->PhoneNumber = count.PhoneNumber;
    this->DarkestSecret = count.DarkestSecret;
}

std::string revers_string(std::string s)
{
    if (s.length() > 10)
    {
        s.resize(10);
        s.resize(13,'.');
    }
    return (s);
}

void Contact::printcontact()
{
    std::string s;

    std::cout<<"index: "<<this->index<<" | ";

    s = revers_string(this->firstname);
    std::cout<<"first name: "<<s<<" | ";

    s = revers_string(this->LastName);
    std::cout<<"last name: "<<s<<" | ";

    s = revers_string(this->NickName);
    std::cout<<"nickname: "<<s<<std::endl;
}

void    Contact::Setindex(int index)
{
    this->index = index;
}

std::string Contact::getfirstname(int index)
{
    if (index < 8 && index >= 0)
        return this->firstname;
    return NULL;
}

Contact::~Contact()
{
}

int    Contact::ADD()
{
    std::cout<<"firstname"<<std::endl;
    getline(std::cin, this->firstname);
    std::cout<<"LastName"<<std::endl;
    getline(std::cin, this->LastName);
    std::cout<<"NickName"<<std::endl;
    getline(std::cin, this->NickName);
    std::cout<<"DarkestSecret"<<std::endl;
    getline(std::cin, this->DarkestSecret);
    std::cout<<"PhoneNumber"<<std::endl;
    getline(std::cin, this->PhoneNumber);
    if (!this->firstname.empty() && !this->LastName.empty() && !this->NickName.empty()
        && !this->DarkestSecret.empty() && !this->PhoneNumber.empty() && srch_error1(this->PhoneNumber) == 0)
    {
        return (0);
    }
    this->firstname.resize(0);
    this->LastName.resize(0);
    this->NickName.resize(0);
    this->DarkestSecret.resize(0);
    this->PhoneNumber.resize(0);
    return (-1);
}
