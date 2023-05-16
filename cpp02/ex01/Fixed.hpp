#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{

	private:
		int                 _fixedValue;
		static const int    _fractionalBits = 8;

	public:

		Fixed(void);
		Fixed(const Fixed &src);
		Fixed(const int n);
		Fixed(const float n);
		~Fixed();

		Fixed &operator=(const Fixed &f);
		
		float 	toFloat( void ) const;
		int     toInt( void ) const;
		
		int getRawBits() const;
		void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &o, Fixed const &f);

#endif