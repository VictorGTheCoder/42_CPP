#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

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
		
		bool operator>(const Fixed &f);
		bool operator<(const Fixed &f);
		bool operator>=(const Fixed &f);
		bool operator<=(const Fixed &f);
		bool operator==(const Fixed &f);
		bool operator!=(const Fixed &f);
		
		Fixed operator+(const Fixed &f);		
		Fixed operator-(const Fixed &f);
		Fixed operator*(const Fixed &f);
		Fixed operator/(const Fixed &f);

		Fixed &operator++(void);
		Fixed &operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);

		static Fixed &max(Fixed &a, Fixed &b);
		static const Fixed &max(const Fixed &a, const Fixed &b);

		static Fixed &min(Fixed &a, Fixed &b);
		static const Fixed &min(const Fixed &a, const Fixed &b);

		float 	toFloat( void ) const;
		int     toInt( void ) const;
		
		int getRawBits() const;
		void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &o, Fixed const &f);

#endif