#include "Fixed.hpp"

int main( void ) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl;
	std::cout << "----- My tests -----" << std::endl;

	std::cout << std::endl;
	Fixed c(a);
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;

	std::cout << std::endl;
	std::cout << "Max (a,b): " << Fixed::max(a,b) << std::endl;
	std::cout << "Min (a,b): " << Fixed::min(a,b) << std::endl;
	std::cout << "Max (a,c): " << Fixed::max(a,c) << std::endl;
	std::cout << "Min (a,c): " << Fixed::min(a,c) << std::endl;	

	std::cout << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a > c: " << (a > c) << std::endl;
	std::cout << "a < c: " << (a < c) << std::endl;

	std::cout << std::endl;
	std::cout << "a >= c: " << (a >= c) << std::endl;
	std::cout << "a <= c: " << (a <= c) << std::endl;
	std::cout << "a == c: " << (a == c) << std::endl;
	std::cout << "a != c: " << (a != c) << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != c: " << (a != c) << std::endl;

	std::cout << std::endl;
	Fixed d(10);
	std::cout << "d: " << d << std::endl;
	std::cout << "d + 1: " << (d + 1) << std::endl;
	std::cout << "d - 1: " << (d - 1) << std::endl;
	std::cout << "d * 2: " << (d * 2) << std::endl;
	std::cout << "d / 2: " << (d / 2) << std::endl;

	std::cout << std::endl;
	std::cout << "a: " << a << std::endl;

	std::cout << std::endl;
	std::cout << "++a: " << (++a) << std::endl;
	std::cout << "a: " << a << std::endl;

	std::cout << std::endl;
	std::cout << "a++: " << (a++) << std::endl;
	std::cout << "a: " << a << std::endl;

	std::cout << std::endl;
	std::cout << "--a: " << (--a) << std::endl;
	std::cout << "a: " << a << std::endl;

	std::cout << std::endl;
	std::cout << "a--: " << (a--) << std::endl;
	std::cout << "a: " << a << std::endl;

	return 0;
}