#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int fixed_point_value;
		static const int bits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const int n);
		Fixed(const float f);
		Fixed(const Fixed &f2);
		Fixed& operator=(const Fixed &f2);
		int getRawBits( void ) const;
		void setRawBits( int const raw ) ;
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream &out, const Fixed &a);

#endif
