#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap( void );
		ScavTrap( std::string name );
		ScavTrap( const ScavTrap & c2 );
		~ScavTrap( void );
		ScavTrap& operator = ( const ScavTrap &c2 );
		void	attack( std::string const & target );
		void	guardgate( void );
};

#endif
