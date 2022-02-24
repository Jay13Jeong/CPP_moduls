#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

//이 클래스는 참조변수로 반드시 무기를 받고 만들어진다.
class HumanA
{
	private:
		std::string	name;
		Weapon		&weapon; 
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA(void);
		void		attack(void);
};

#endif
