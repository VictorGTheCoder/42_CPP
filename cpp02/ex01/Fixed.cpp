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
	*this = src;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	_fixedValue = n << _fractionalBits;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	_fixedValue = round(n * (1 << _fractionalBits));
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

float Fixed::toFloat(void) const
{
    return static_cast<float>(_fixedValue) / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return _fixedValue >> _fractionalBits;
}

int Fixed::getRawBits(void) const
{
	return this->_fixedValue;
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedValue = raw;
}
