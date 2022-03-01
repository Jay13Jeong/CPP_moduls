#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	protected:
		std::string	ideas[100];
	public:
		Brain();
		Brain( const Brain &b2 );
		~Brain();
		Brain& operator = ( const Brain &b2 );
};


#endif
