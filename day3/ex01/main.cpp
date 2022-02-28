#include "ScavTrap.hpp"


int main( void )
{
	ScavTrap jim("jim");

	jim.guardgate();
	jim.attack("bob");;
	jim.takeDamage(6);
	jim.beRepaired(5);
	jim.attack("bob");
	jim.takeDamage(1<<15);
	jim.beRepaired(10);

	return (0);
}
