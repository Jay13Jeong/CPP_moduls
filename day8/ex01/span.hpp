#ifndef SPAN_HPP
#define SPAN_HPP

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
	private:
		unsigned int		N;
		std::vector<int>	vec;
		Span();
	public:
		Span( unsigned int N );
		Span( const Span &s2 );
		~Span();
		Span& operator = ( const Span &s2 );
		void	addNumber( int num );
		int		longestSpan();
		int		shortestSpan();

		class CanNotCompare: public std::exception
		{
			virtual const char* what() const throw();
		};
		class CanNotAdd: public std::exception
		{
			virtual const char* what() const throw();
		};
};

#endif
