#include "Bureaucrat.hpp"

int main()
{
	int i = 0;
	std::string s[] = {"A", "B", "C", "D", "E"};
	int j[] = { 0, 150, 1, 160, 149};

	Bureaucrat b1(j[1],s[0]);
	std::cout<<b1<<std::endl;
	b1.increment();
	std::cout<<b1<<std::endl;
	b1.decrement();
	std::cout<<b1<<std::endl<<std::endl;

	while (i < 5)
	{
		try
		{
			Bureaucrat *p = new Bureaucrat(j[i],s[i]);
			(void) p;
			/* do some stuff with bureaucrats */
			Bureaucrat b(j[i],s[i]);
			std::cout<<b<<std::endl;
			b++;
			std::cout<<b<<std::endl;
			b--;
			std::cout<<b<<std::endl;
		}
		catch (std::exception & e)
		{
			/* handle exception */
			std::cout<<e.what()<<std::endl;
		}
		// system("leaks so_long");
		// while(1);
		i++;
	}
}
