#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat();
		Cat( const Cat &c2 );
		~Cat();
		Cat& operator=( const Cat &c2 );
		void	makeSound( void ) const;
};

#endif
