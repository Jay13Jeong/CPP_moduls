#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal();
		WrongAnimal( const WrongAnimal &w2 );
		~WrongAnimal();
		WrongAnimal& operator = ( const WrongAnimal &w2 );
		std::string	getType() const;
		void		makeSound() const;
};

#endif
