#include "HumanB.hpp"

//생성자 메소드.
HumanB::HumanB(std::string name1)
{
	this->name = name1;
	this->weapon = NULL;
}

//소멸자 메소드.
HumanB::~HumanB()
{
	std::cout << "HumanB Destructed" << std::endl;
}

//공격 메소드.
void	HumanB::attack()
{
	if (this->weapon != NULL)
		std::cout << this->name << " attacks with his ";
		std::cout << weapon->getType() << std::endl;
}

//매개변수로 받은 무기로 B의 무기를 설정하는 메소드.
void	HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
