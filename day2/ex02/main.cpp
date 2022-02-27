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

	// Fixed const c( Fixed( 5.05f ) / Fixed( 2 ) );
	// std::cout << c << std::endl;
	// Fixed const d( Fixed( 5.05f ) + Fixed( 2 ) );
	// std::cout << d << std::endl;
	// Fixed const e( Fixed( 5.05f ) - Fixed( 2 ) );
	// std::cout << e << std::endl;
	// std::cout << (Fixed( 2 ) != Fixed( 2 )) << std::endl;
	// std::cout << (Fixed( 2 ) != Fixed( 3 )) << std::endl;
	return 0;
}
