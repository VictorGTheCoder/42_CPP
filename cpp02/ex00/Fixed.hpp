#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>


class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed &src);
        ~Fixed();
        int getRawBits() const;
        void setRawBits(int const raw);
        Fixed &operator=(const Fixed &rhs);

    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;
};

#endif