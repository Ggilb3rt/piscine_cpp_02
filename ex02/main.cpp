#include <iostream>
#include "Fixed.hpp"


void    subject_test()
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
    std::cout << Fixed::min( a, b ) << std::endl;
}

int main( void ) {
    
    Fixed   a = 42;
    Fixed   b(23.345f);
    Fixed   c = -10.3f;
    Fixed   zero;

    std::cout << "a = " << a << " ; b = " << b <<  " ; c = " << c << std::endl;
    std::cout << "Arithmetic operators" << std::endl;
    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "a + b + c = " << (a + b + c) << std::endl;
    std::cout << "a - b = " << (a - b) << std::endl;
    std::cout << "b - a = " << (b - a) << std::endl;
    std::cout << "b - a - c = " << (b - a - c) << std::endl;
    std::cout << "a * b = " << (a * b) << std::endl;
    std::cout << "b * zero = " << (b * zero) << std::endl;
    std::cout << "a / b = " << (a / b) << std::endl;
    std::cout << "b / a = " << (b / a) << std::endl;
    std::cout << "a / zero (0o0) = " << (a / zero) << std::endl << std::endl;

    std::cout << "Comparison operators" << std::endl;
    std::cout << "b > a : " << (b > a) << "\t| real " << (23.345f > 42) << std::endl;
    std::cout << "b < a : " << (b < a) << "\t| real " << (23.345f < 42) << std::endl;
    std::cout << "b == b : " << (b == b) << "\t| real " << (23.345f == 23.345f) << std::endl;
    std::cout << "b != a : " << (b != a) << "\t| real " << (23.345f != 42) << std::endl;
    std::cout << "c < b : " << (c < b) << "\t| real " << (-10.3f < 23.345f) << std::endl;
    std::cout << "c > b : " << (c > b) << "\t| real " << (-10.3f > 23.345f) << std::endl;
    std::cout << "c == b : " << (c == b) << "\t| real " << (-10.3f == 23.345f) << std::endl;
    std::cout << "c != b : " << (c != b) << "\t| real " << (-10.3f != 23.345f) << std::endl;

    std::cout << std::endl << "Increment/decrement operators" << std::endl;
    std::cout << "++a : " << ++a << std::endl;
    std::cout << "a++ : " << a++ << " | " << a << std::endl;
    std::cout << "--a : " << --a << std::endl;
    std::cout << "a-- : " << a-- << " | " << a << std::endl << std::endl;

    std::cout << std::endl << "Subject tests + min()" << std::endl;
    subject_test();
    return (0);
}
