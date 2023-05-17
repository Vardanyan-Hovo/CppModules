#include <iostream>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int	srch_error(std::string index_str)
{
	int i = 0;

	while (index_str[i])
	{
		if (!(index_str[i] >= 48 && index_str[i] <= 57))
			return (-1);
		i++;
	}
	if (i > 8)
		return (-1);
	return (0);
}

int main()
{
	PhoneBook 	book;
	Contact		contact;
	std::string s;
	std::string index_str;
	int 		index;

	while (1)
	{
		std::cout<<"write what you want to do"<< std::endl;
		getline(std::cin, s);
		if (s.compare("ADD") == 0)
		{
			if (contact.ADD() == 0)
			{
				book.ADD(contact);
				std::cout<<"<<<< ADDED >>>>"<<std::endl;
			}
			else
			{
				std::cout<<"cannot add because input incorrect\n";
			}
		}
		else if (s.compare("SEARCH") == 0)
		{
			getline(std::cin, index_str);
			if (srch_error(index_str) == 0)
			{
				index = (int)(std::stoi(index_str));
				book.SEARCH(index);
			}
			else
				std::cout<<"input incorrect"<<std::endl;
		}
		else if (s.compare("EXIT") == 0)
		{
			book.EXIT();
		}
		else if (s.compare("ALL") == 0)
		{
			book.All();
		}else
		{
			std::cout<<"instruct incorrectly"<<std::endl;
		}
	}
}