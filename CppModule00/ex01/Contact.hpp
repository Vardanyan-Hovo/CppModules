#ifndef CONTACT_H
# define CONTACT_H

#include <string>

class Contact
{
	public:
		Contact();
		~Contact();

	public:
		void	SetArgments(Contact count, int i);
		void    printcontact();
		int		ADD();
		void	Setindex(int index);
		std::string		getfirstname(int index);

	private:
		int			index;
		std::string	firstname;
		std::string	LastName;
		std::string	NickName; 
		std::string	DarkestSecret;
		std::string	PhoneNumber;
};

#endif