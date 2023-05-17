#include "Harl.hpp"

Harl::Harl()
{

}

Harl::~Harl()
{

}

void Harl::debug( void ) 
{
	std::cout<<"[ DEBUG ]"<<std::endl;
	std::cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-"<<std::endl
				<<"ketchup burger. I really do!\n"<<std::endl;
}

void Harl::info( void )
{
	std::cout<<"[ INFO ]"<<std::endl;
	std::cout<<"I cannot believe adding extra bacon costs more money. You didn’t put"<<std::endl<<
		"enough bacon in my burger! If you did, I wouldn’t be asking for more!\n"<<std::endl;
}

void Harl::warning(void )
{
	std::cout<<"[ WARNING ]"<<std::endl;
	std::cout<<"I think I deserve to have some extra bacon for free. I’ve been coming for"<<std::endl
		<<"years whereas you started working here since last month.\n"<<std::endl;
}

void Harl::error(void)
{
	std::cout<<"[ ERROR ]"<<std::endl;
	std::cout<<"This is unacceptable! I want to speak to the manager now.\n"<<std::endl;
}

void Harl::complain(std::string level)
{
	typedef void (Harl::*FUNC)(void);
	enum E
	{
		DEBUG,
		INFO,
		WARNING,
		ERROR
	};
	E e;
	FUNC f[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string s[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;

	this->level = &level;
	while ((this->level)->compare(s[i]) && i < 4)
		i++;
	e = static_cast<E>(i);
	switch (e)
	{
		case DEBUG:
			(this->*f[DEBUG])();
			break;
		case INFO:
			(this->*f[INFO])();
			break;
		case WARNING:
			(this->*f[WARNING])();
		case ERROR:
			(this->*f[ERROR])();
			break;
		default:
			std::cout<<"[ Probably complaining about insignificant problems ]"<<std::endl;
	}
}
