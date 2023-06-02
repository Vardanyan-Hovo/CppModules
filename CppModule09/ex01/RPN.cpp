#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(std::string str):s(str)
{
}

RPN::RPN(const RPN &obj):s(obj.getString()), number(obj.getNumber())
{
}

RPN &RPN::operator=(const RPN &obj)
{
	if (this != &obj)
	{
		this->s = obj.getString();
		this->number = obj.getNumber();
	}
	return *this;
}

RPN::~RPN()
{
}

std::string RPN::getString() const
{
	return s;
}

std::stack<int> RPN::getNumber() const
{
	return this->number;
}

void RPN::chackInput(void)
{
	int num = 0;
	int op = 0;
	int sp = 0;
	int i = -1;

	while(s[++i])
	{
		if (isdigit(s[i]))
		{
			num++;
		}
		else if (s[i] == '+' || s[i] == '-' || s[i] == '/' || s[i] == '*')
		{
			op++;
		}
		else if (s[i] == ' ')
		{
			sp++;
		}
		else
			throw RPN::Excp("Error");
	}
	if (op != num - 1 || !isdigit(s[0])|| (op + num + sp != i))
		throw RPN::Excp("Error");
}

void RPN::operator+(const int x)
{
	(void)x;
	if (this->number.empty())
		throw RPN::Excp("Error opeartion");
	int a1 = number.top();
	number.pop();
	if (this->number.empty())
		throw RPN::Excp("Error opeartion");
	long int a2 = number.top();
	number.pop();
	a2 += a1;
	if (a2 >= INT_MAX || a2 <= INT_MIN)
	{
		throw RPN::Excp("Error number out int");
	}
	number.push(static_cast<int>(a2));
}

void RPN::operator-(int x)
{
	(void)x;

	if (this->number.empty())
		throw RPN::Excp("Error opeartion");
	int a1 = number.top();
	number.pop();
	if (this->number.empty())
		throw RPN::Excp("Error operation ");
	long int a2 = number.top();
	number.pop();
	a2 -= a1;
	if (a2 >= INT_MAX || a2 <= INT_MIN)
	{
		throw RPN::Excp("Error number out int");
	}
	number.push(static_cast<int>(a2));
}

void RPN::operator*(int x)
{
	(void)x;

	if (this->number.empty())
		throw RPN::Excp("Error opeartion");
	int a1 = number.top();
	number.pop();
	if (this->number.empty())
		throw RPN::Excp("Error operation ");
	long int a2 = number.top();
	number.pop();
	a2 *= a1;
	if (a2 >= INT_MAX || a2 <= INT_MIN)
	{
		throw RPN::Excp("Error number out int");
	}
	number.push(static_cast<int>(a2));
}

void RPN::operator/(int x)
{
	(void)x;

	if (this->number.empty())
		throw RPN::Excp("Error opeartion");
	int a1 = number.top();
	number.pop();
	if (a1 == 0)
		throw RPN::Excp("Error divide by 0");
	if (this->number.empty())
		throw RPN::Excp("Error operation ");
	long int a2 = number.top();
	number.pop();
	a2 /= a1;
	if (a1 >= INT_MAX || a1 <= INT_MIN)
	{
		throw RPN::Excp("Error number out int");
	}
	number.push(static_cast<int>(a2));
}

void RPN::logicMath()
{
	for (size_t i = 0; i < this->s.length(); i++)
	{
		switch(s[i])
		{
			case '+':
				*this + 1;
				break ;
			case '-':
				*this - 1;
				break ;
			case '*':
				*this * 1;
				break ;
			case '/':
				*this / 1;
				break ;
			default:
			if (isdigit(s[i]))
			{
				number.push(s[i] - 48);
			}
		}
	}
	std::cout<<number.top()<<std::endl;
}

RPN::Excp::Excp(const char *str):s(str)
{
}

const char *RPN::Excp::what() const throw()
{
	return s;
}
