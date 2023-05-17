#include <iostream>
#include <sstream>
#include <fstream>

void funcCheck(std::ifstream &fd, std::ofstream &fdNew, std::string &s1, std::string &s2)
{
	std::string strRead;
	size_t index;
	size_t len;
	char c;

	while(!fd.eof() && fd>>std::noskipws>>c)
	{
		strRead += c;
	}
	len = strRead.length();
	for(size_t i = 0; i < len; i++)
	{
		index = strRead.find(s1, i);
		if (index != std::string::npos && index == i)
		{
			fdNew<<s2;
			i += s1.length() - 1;
		}
		else
			fdNew<<strRead[i];
	}
}

int main(int argc, char *argv[])
{

	std::string s1;
	std::string s2;
	std::ifstream fd;
	std::ofstream fdNew;

	if (argc != 4)
	{
		std::cout<<"the input is not correct"<<std::endl;
		return 0;
	}
	s1 = argv[2];
	s2 = argv[3];
	fd.open(argv[1],std::ios::in);
	if (!fd)
	{
		std::perror("File opening failed");
		return 0;
	}
	fdNew.open(std::strcat(argv[1],".replace"), std::ios::out);
	if (!fdNew)
	{
		std::perror("File opening failed");
		return 0;
	}
	funcCheck(fd, fdNew, s1, s2);
	fd.close();
	fdNew.close();
	return 0;
}
