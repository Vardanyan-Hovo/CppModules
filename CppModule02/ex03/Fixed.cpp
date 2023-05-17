#include "Fixed.hpp"

int const Fixed::fractional = 8;

Fixed::Fixed():value(0)
{
}

Fixed::Fixed(int value)
{
	this->value = (value * (1 << this->fractional));
}

Fixed::Fixed(float value)
{
	this->value = roundf(value * (1 << fractional));
}

float Fixed::toFloat( void ) const
{
	return (static_cast<float>(value)/(1 << fractional));
}

int Fixed::toInt( void ) const
{
	return (static_cast<int>(value)/(1 << fractional));
}

Fixed::Fixed(Fixed const &fixed)
{
	*this = const_cast<Fixed&>(fixed);
}

int Fixed::getRawBits(void) const
{
	return value;
}

void Fixed::setRawBits( int const raw )
{
	value = raw;
}

Fixed::~Fixed()
{
}

//-------------------------------  overload  ---------------------.


std::ostream& operator<<(std::ostream &os_t, Fixed const &f)
{
	os_t<<f.toFloat();
	return os_t;
}

Fixed &min(Fixed &f1 , Fixed &f2)
{
	return f1.min(f1, f2);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
	{
		return (f1);
	}
	return (f2);
}

Fixed const &Fixed::min(Fixed const &f1, Fixed const &f2)
{
	if (f1.getRawBits() < f2.getRawBits())
	{
		return (f1);
	}
	return (f2);
}

Fixed const &min(Fixed const &f1 , Fixed const &f2)
{
	return f1.min(f1, f2);
}

Fixed &Fixed::max(Fixed &f1,Fixed &f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return (f1);
	return (f2);
}

Fixed &max(Fixed &f1, Fixed &f2)
{
	return (f1.max(f1, f2));
}

Fixed const& Fixed::max(Fixed const &f1, Fixed const &f2)
{
	if (f1.getRawBits() > f2.getRawBits())
		return f1;
	return f2;
}

Fixed const &max(Fixed const &f1, Fixed const &f2)
{
	return (f1.max(f1, f2));
}

int operator>(int i, Fixed const &f)
{
	if (i > f.getRawBits())
		return 1;
	return 0;
}

int operator<(int i, Fixed const &f)
{
	if (i < f.getRawBits())
		return 1;
	return 0;
}

int operator>=(int i, Fixed const &f)
{
	if (i >= f.getRawBits())
		return 1;
	return 0;
}

int operator<=(int i, Fixed const &f)
{
	if (i <= f.getRawBits())
		return 1;
	return 0;
}

int operator==(int i, Fixed const &f)
{
	if (i == f.getRawBits())
		return 1;
	return 0;
}

int operator!=(int i, Fixed const &f)
{
	if (i != f.getRawBits())
		return 1;
	return 0;
}

Fixed operator+(int i, Fixed const &f)
{
	Fixed x = f;

	x.setRawBits(i + f.getRawBits());
	return (x);
}

Fixed operator-(int i, Fixed const &f)
{
	Fixed x = f;

	x.setRawBits(i - f.getRawBits());
	return (x);
}

Fixed operator/(int i, Fixed const &f)
{
	Fixed x = f;

	x.setRawBits(i / f.getRawBits());
	return (x);
}

Fixed operator*(int i, Fixed const &f)
{
	Fixed x = f;
	x.setRawBits(i * f.getRawBits());
	return x; 
}

//------------------------  this  -----------------------------


Fixed& Fixed::operator=(Fixed const &fixed)
{
	if (this == &fixed)
	{
		return *this;
	}
	this->setRawBits(fixed.getRawBits());
	return *this;
}

int Fixed::operator>(Fixed const &fixed) const
{
	if ((this->getRawBits()) > (fixed.getRawBits()))
	{
		return 1;
	}
	return 0;
}

int Fixed::operator>(int i) const
{
	if (this->getRawBits() > i)
	{
		return 1;
	}
	return 0;
}

int Fixed::operator>(float i) const
{
	if (this->getRawBits() > i)
	{
		return 1;
	}
	return 0;
}

int Fixed::operator<(Fixed const &fixed) const
{
	if (this->getRawBits() < fixed.getRawBits())
	{
		return 1;
	}
	return 0;
}

int Fixed::operator<(int i) const
{
	if (this->getRawBits() < i)
	{
		return 1;
	}
	return 0;
}

int Fixed::operator<(float i) const
{
	if (this->getRawBits() < i)
	{
		return 1;
	}
	return 0;
}

int Fixed::operator>=(Fixed const &fixed) const
{
	if (this->getRawBits() >= fixed.getRawBits())
	{
		return 1;
	}
	return 0;
}

int Fixed::operator>=(int i) const
{
	if (this->getRawBits() >= i)
	{
		return 1;
	}
	return 0;
}

int Fixed::operator>=(float i) const
{
	if (this->getRawBits() >= i)
	{
		return 1;
	}
	return 0;
}

int Fixed::operator<=(Fixed const &fixed) const
{
	if (this->getRawBits() <= fixed.getRawBits())
	{
		return 1;
	}
	return 0;
}

int Fixed::operator<=(int i) const
{
	if (this->getRawBits() <= i)
	{
		return 1;
	}
	return 0;
}

int Fixed::operator<=(float i) const
{
	if (this->getRawBits() <= i)
	{
		return 1;
	}
	return 0;
}

int Fixed::operator==(Fixed const &fixed) const
{
	if (this->getRawBits() == fixed.getRawBits())
	{
		return 1;
	}
	return 0;
}

int Fixed::operator==(int i) const
{
	if (this->getRawBits() == i)
	{
		return 1;
	}
	return 0;
}

int Fixed::operator!=(Fixed const &fixed) const
{
	if (this->getRawBits() != fixed.getRawBits())
	{
		return 1;
	}
	return 0;
}

int Fixed::operator!=(int i) const
{
	if (this->getRawBits() != i)
	{
		return 1;
	}
	return 0;
}

int Fixed::operator!=(float i) const
{
	if (this->getRawBits() != i)
	{
		return 1;
	}
	return 0;
}

Fixed Fixed::operator+(Fixed const &fixed) const
{
	Fixed x;

	x.setRawBits(fixed.getRawBits() + this->getRawBits());
	return x;
}

Fixed Fixed::operator+(int i) const
{
	Fixed x;

	x.setRawBits(this->getRawBits() + i);
	return (x);
}

Fixed Fixed::operator-(Fixed const &fixed) const
{
	Fixed x;

	x.setRawBits(this->getRawBits() - fixed.getRawBits());
	return x;
	// return this->value - fixed.getRawBits();
}

Fixed Fixed::operator-(int i) const
{
	Fixed x;

	x.setRawBits(this->getRawBits() - i);
	return (x);
}

Fixed Fixed::operator*(Fixed const &fixed) const
{
	Fixed f(*this);

	f.setRawBits((fixed.getRawBits() * this->getRawBits())/(1 << fractional));
	return f;
}

Fixed Fixed::operator*(int i) const
{
	Fixed f(*this);
	f.setRawBits(this->getRawBits() * i);
	return (f);
}

Fixed Fixed::operator/(Fixed const &fixed) const
{
	if (fixed.getRawBits() == 0)
		throw std::logic_error("not can division on zero");

	Fixed f = (this->toFloat() / fixed.toFloat());
	return (f);
}

Fixed Fixed::operator/(int i) const
{
	Fixed f = *this;

	f.setRawBits(this->value / i);
	return (f);
}

Fixed &Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

Fixed Fixed::operator++( int )
{
	Fixed x =  *this;
	this->value++;
	return x;
}

Fixed &Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

Fixed Fixed::operator--( int )
{
	Fixed f = this->value;
	this->value--;
	return f;
}
