#include "Zombie.hpp"

void	destroyed(Zombie **zombi, int n)
{
	int i = 0;

	while (n > 0 && i < n)
	{
		delete zombi[i];
		i++;
	}
}

int main()
{
	int i;
	std::string s;
	Zombie *zombi[100];
	std::string name;

	i = 0;
	while(1)
	{
		std::cout<<"0 for newZombi |  1 for randomChump   |  2 for breack\n";
		std::getline(std::cin,s);
		if (s.compare("0") == 0)
		{
			std::cout<<"input name: ";
			std::getline(std::cin, name);
			if ((name.compare("") != 0) && i < 100)
			{
				zombi[i] = newZombie(name);
				i++;
			}
		} else if (s.compare("1") == 0)
		{ 	
			std::cout<<"input name: ";
			std::getline(std::cin, name);
			randomChump(name );
		} else if (s.compare("2") == 0)
		{
			if (i > 0)
			{
				destroyed( zombi, i);
				std::cout<<std::endl;
			}
			break ;
		}
		name = "";
		s = "";
	}
}
