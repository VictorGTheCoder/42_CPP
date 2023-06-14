#include "Fixed.hpp"

#include <iostream>

int main( void )
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << b << std::endl;

    std::cout << Fixed::max( a, b ) << std::endl;

    std::cout << "\nTEST\n\n";
    Fixed c(2);
    Fixed d(3);
    std::cout << Fixed::max( b, a ) << std::endl;
    std::cout << Fixed::min( a, b ) << std::endl;
    std::cout << Fixed::max( d, c ) << std::endl;
    std::cout << Fixed::min( d, c ) << std::endl;
    a = c + d + b;
    std::cout << a << std::endl;
    std::cout << d - c << std::endl;
    return 0;
}