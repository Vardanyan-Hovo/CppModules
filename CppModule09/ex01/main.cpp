#include "RPN.hpp"

int main(int argc, char *argv[])
{
	std::string s;

	if (argc < 2)
	{
		std::cout<<"Error"<<std::endl;
		return 1;
	}
	int i = -1;
	int j = 0;
	while (argv[++j])
	{
		i = -1;
		while(argv[j][++i])
		{
			s += argv[j][i];
		}
	}
	RPN R(s);
	try{
		R.chackInput();
		R.logicMath();
	}
	catch(std::exception &e)
	{
		std::cout<<e.what()<<std::endl;
	}
	return 0;
}

