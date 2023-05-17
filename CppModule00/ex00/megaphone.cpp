#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
	int	i = 1;
	int	j = 0;

	if (argc == 1)
	{
		std::cout<<"* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return (0);
	}
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] <= 122 && argv[i][j] >=97)
				std::cout<<(char)(argv[i][j] - 32);
			else
				std::cout<<argv[i][j];
			j++;
		}
		i++;
		if (argv[i])
			std::cout<<(char)32;
	}
	std::cout<<std::endl;
	return (0);
}