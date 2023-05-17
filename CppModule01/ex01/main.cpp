#include "Zombie.hpp"

int srch_error(std::string index_str)
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

void	destroyed(Zombie **zombi)
{
	delete [] *(zombi);
}

int main()
{
	std::string name;
	std::string number;
	int N;
	Zombie *Horde;

	N = 0;
	std::cout<<"input name :";
	std::getline(std::cin, name);
	std::cout<<"input number Horde: ";
	std::getline(std::cin, number);
	if (number.length() > 9 || srch_error(number) != 0 || name.empty())
	{
		std::cout<<"input incorect\n";
		return 1;
	}
	N = std::stoi(number);
	Horde = zombieHorde(N, name );
	for (size_t i = 0; i < (size_t)N; i++)
		Horde[i].announce();
	destroyed(&Horde);
}
