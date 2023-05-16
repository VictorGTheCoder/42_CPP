#include "Fixed.hpp"

Fixed::Fixed() : _fixedValue(0)
{
	std::cout << "Default constructor called\n";
}


Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedValue = src.getRawBits();
}

Fixed::Fixed(const int n) : _fixedValue(n)
{
	std::cout << "Int constructor called" << std::endl;
	this->setRawBits(n);
}

Fixed::Fixed(const float n) : _fixedValue(n)
{
	std::cout << "Float constructor called" << std::endl;
	this->setRawBits(n);
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->_fixedValue);
}

int Fixed::toInt(void) const
{
	return static_cast<int>(this->_fixedValue);
}


Fixed &Fixed::operator=(const Fixed &f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &f)
	{
		_fixedValue = f.getRawBits();
	}
	return *this;
}
std::ostream &operator<<(std::ostream &o, Fixed const &f)
{
	o << f.toFloat();
	return o;
}


int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedValue = raw;
}


