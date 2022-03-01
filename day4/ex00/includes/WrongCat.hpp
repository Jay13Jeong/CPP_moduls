#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		WrongCat( const WrongCat &w2 );
		~WrongCat();
		WrongCat& operator = ( const WrongCat &w2 );
		void	makeSound() const;
};

#endif
