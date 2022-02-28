#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string	Name;
		int			HitPoints;
		int			Energy_points;
		int			Attack_damage;
	public:
		ClapTrap();
		ClapTrap( std::string name );
		ClapTrap( const ClapTrap &c2 );
		~ClapTrap();
		ClapTrap& operator = ( const ClapTrap &c2 );
		void	attack( std::string const & target );
		void	takeDamage( unsigned int amount );
		void	beRepaired( unsigned int amount );
};

#endif
