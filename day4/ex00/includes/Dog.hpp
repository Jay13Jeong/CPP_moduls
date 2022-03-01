#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
	public:
		Dog();
		Dog( const Dog &d2 );
		~Dog();
		Dog& operator = ( const Dog &d2 );
		void makeSound() const;
};

#endif
