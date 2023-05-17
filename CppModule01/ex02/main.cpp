#include <iostream>
#include <string>

int main()
{
	std::string name;
	name = "HI THIS IS BRAIN";

	std::string *stringPTR = &name;
	std::string &stringREF = name;

	std::cout<< "&name     : "<<&name<<std::endl;
	std::cout<< "stringPTR : "<<stringPTR<<std::endl;
	std::cout<< "&stringREF: "<<&stringREF<<std::endl;
	std::cout<<std::endl;

	std::cout<< "name     : "<<name<<std::endl;
	std::cout<< "stringPTR: "<<*stringPTR<<std::endl;
	std::cout<< "stringREF: "<<stringREF<<std::endl;
}
