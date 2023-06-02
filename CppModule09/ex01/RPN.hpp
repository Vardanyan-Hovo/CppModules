#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <exception>
#include <cmath>

class RPN
{
	public:
		RPN();
		RPN(std::string std);
		RPN(const RPN &obj);
		RPN & operator=(const RPN &obj);
		~RPN();
	public:
		std::stack<int> getNumber(void) const;
		std::string getString(void) const;
		void chackInput(void);
		void logicMath();
		class Excp : public std::exception
		{
			public:
				Excp(const char *s);
				virtual const char* what() const throw();
			private:
				const char *s;
		};
		void operator+(int);
		void operator-(int);
		void operator*(int);
		void operator/(int);
	private:
		std::string s;
		std::stack <int>number;
};

#endif

