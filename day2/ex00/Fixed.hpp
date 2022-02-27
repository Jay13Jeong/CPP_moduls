#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int fixed_point_value;
		static const int bits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &f2);
		Fixed& operator=(const Fixed &f2);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};

#endif
