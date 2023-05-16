#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>


class Fixed
{

    private:
        int                 _fixedValue;
        static const int    _fractionalBits = 8;

    public:

        Fixed(void);
        Fixed(const Fixed &src);
        ~Fixed();

        Fixed &operator=(const Fixed &rhs);
        
        int getRawBits() const;
        void setRawBits(int const raw);
};

#endif