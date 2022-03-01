#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal();
		Animal( const Animal &a2 );
		virtual ~Animal();
		Animal& operator = ( const Animal &a2 );
		std::string	getType() const;
		virtual void	makeSound() const;
};

#endif
