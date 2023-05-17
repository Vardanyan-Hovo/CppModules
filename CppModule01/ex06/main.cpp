#include "Harl.hpp"

int main(int argc, char *argv[])
{
	Harl h;
	std::string str;
	char *s;
	if (argc != 2)
	{
		std::cout<<"input incorrect"<<std::endl;
		return EXIT_FAILURE;
	}
	s = argv[1];
	while(*s)
	{
		str += *s++;
	}
	h.complain(str);
	return EXIT_SUCCESS;
}
