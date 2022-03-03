#ifndef CASTS_HPP
#define CASTS_HPP

#include <iostream>
#include <string>
#include <cmath>

class Scalar
{
	private:
		char	c;
		bool	isC;
		int		i;
		bool	isI;
		float	f;
		bool	isF;
		double	d;
		bool	isD;
		int		point_len;
		int		get_point_len( char *str );
	public:
		Scalar();
		Scalar( std::string token );
		~Scalar();
		Scalar( const Scalar &s2);
		Scalar & operator = ( const Scalar &s2 );
		void	printScalar() const;
		void	printInfMinus() const;
		void	printInfPlus() const;
		void	printNan() const;
};

#endif
