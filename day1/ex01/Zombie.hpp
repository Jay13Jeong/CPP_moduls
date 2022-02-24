#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <sstream>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void announce(void) const;
		void set_name(const std::string name);
};

Zombie* zombieHorde( int N, std::string name );

#endif
