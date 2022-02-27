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
		Fixed( const int n );
		Fixed( const float f );
		Fixed( const Fixed &f2 );
		int getRawBits( void ) const;
		void setRawBits( int const raw ) ;
		float toFloat( void ) const;
		int toInt( void ) const;
		Fixed& operator = ( const Fixed &f2 );
		bool operator > ( const Fixed &f2 ) const;
		bool operator < ( const Fixed &f2 ) const;
		bool operator >= ( const Fixed &f2 ) const;
		bool operator <= ( const Fixed &f2 ) const;
		bool operator == ( const Fixed &f2 ) const;
		bool operator != ( const Fixed &f2 ) const;
		Fixed operator + ( const Fixed &f2 ) const;
		Fixed operator - ( const Fixed &f2 ) const;
		Fixed operator * ( const Fixed &f2 ) const;
		Fixed operator / ( const Fixed &f2 ) const;
		Fixed& operator ++ ( void );
		Fixed& operator -- ( void );
		Fixed operator ++ ( int );
		Fixed operator -- ( int );
		static Fixed& min( Fixed &f1, Fixed &f2);
		const static Fixed& min( const Fixed &f1, const Fixed &f2);
		static Fixed& max( Fixed &f1, Fixed &f2);
		const static Fixed& max( const Fixed &f1, const Fixed &f2);
};

std::ostream& operator<<(std::ostream &out, const Fixed &a);

#endif
