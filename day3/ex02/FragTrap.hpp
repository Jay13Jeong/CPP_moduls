#include "ClapTrap.hpp"

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap( std::string name );
		FragTrap( const FragTrap &c2 );
		~FragTrap();
		FragTrap& operator = ( const FragTrap &c2 );
		void	highFivesGuys( void );
};

#endif
