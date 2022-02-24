#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

//이 클래스는 생성시 무기가 없으며, 추가 메소드로 무기를 받는다.
class HumanB
{
	private:
		std::string	name;
		Weapon		*weapon;
	public:
		HumanB(std::string name);
		~HumanB(void);
		void		attack(void);
		void		setWeapon(Weapon &weapon);
};

#endif
