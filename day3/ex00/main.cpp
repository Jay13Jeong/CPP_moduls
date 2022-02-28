#include "ClapTrap.hpp"


int main( void )
{
	ClapTrap jim("jim");

	jim.attack("bob");;
	jim.takeDamage(6);
	jim.beRepaired(5);
	jim.attack("bob");
	jim.takeDamage(1<<15);
	jim.beRepaired(10);

	return (0);
}
