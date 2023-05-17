#include "Fixed.hpp"

Fixed::Fixed() : _fixedValue(0) {}

Fixed::~Fixed() {}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

Fixed::Fixed(const int n)
{
	_fixedValue = n << _fractionalBits;
}

Fixed::Fixed(const float n)
{
	_fixedValue = round(n * (1 << _fractionalBits));
}

Fixed &Fixed::operator=(const Fixed &f)
{
	if (this != &f)
	{
		_fixedValue = f.getRawBits();
	}
	return *this;
}

bool Fixed::operator>(const Fixed &f)
{
	if (this->getRawBits() > f.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<(const Fixed &f)
{
	if (this->getRawBits() < f.getRawBits())
		return (true);
	return (false);
}


bool Fixed::operator>=(const Fixed &f)
{
	if (this->getRawBits() >= f.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator<=(const Fixed &f)
{
	if (this->getRawBits() <= f.getRawBits())
		return (true);
	return (false);
}


bool Fixed::operator==(const Fixed &f)
{
	if (this->getRawBits() == f.getRawBits())
		return (true);
	return (false);
}

bool Fixed::operator!=(const Fixed &f)
{
	if (this->getRawBits() < f.getRawBits())
		return (true);
	return (false);
}

Fixed Fixed::operator+(const Fixed &f)
{
	Fixed new_fixed;

	new_fixed.setRawBits(this->getRawBits() + f.getRawBits());
	return (new_fixed);
}

Fixed Fixed::operator-(const Fixed &f)
{
	Fixed new_fixed;

	new_fixed.setRawBits(this->getRawBits() - f.getRawBits());
	return (new_fixed);
}

Fixed Fixed::operator*(const Fixed &f)
{
	Fixed new_fixed ( this->toFloat()  * f.toFloat());
	return (new_fixed);
}

Fixed Fixed::operator/(const Fixed &f)
{
	Fixed new_fixed ( this->toFloat()  / f.toFloat());
	return (new_fixed);
}

Fixed &Fixed::operator++(void)
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed &Fixed::operator--(void)
{
	this->setRawBits(this->getRawBits() - 1);
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed cpy(*this);
	++(*this);
	return cpy;
}

Fixed Fixed::operator--(int)
{
	Fixed cpy(*this);
	--(*this);
	return cpy;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);	
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);	
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);	
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);	
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
