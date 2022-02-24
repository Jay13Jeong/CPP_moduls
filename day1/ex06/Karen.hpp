#ifndef KAREN_HPP
#define KAREN_HPP

#include <iostream>
#include <string>

class Karen
{
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
		void	complain_switch(int i);
	public:
		void	filter( std::string level );	
};


#endif
