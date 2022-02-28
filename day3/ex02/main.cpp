#include "FragTrap.hpp"


int main( void )
{
	FragTrap jim("jim");

	jim.highFivesGuys();
	jim.attack("bob");;
	jim.takeDamage(6);
	jim.beRepaired(5);
	jim.attack("bob");
	jim.takeDamage(1<<15);
	jim.beRepaired(10);
	return (0);
}
