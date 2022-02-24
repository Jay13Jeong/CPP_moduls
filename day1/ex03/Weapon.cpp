#include "Weapon.hpp"

//받아온 무기형태를 저장하는 생성자 메소드.
Weapon::Weapon(std::string type)
{
	this->type = type;
}

//무기 소멸자 메소드.
Weapon::~Weapon(void)
{
	std::cout << "Weapon Destructed" << std::endl;
}

//무기의 type을 "상수 참조문자열"로 반환하는 메소드.
const std::string& Weapon::getType(void) const
{
	return this->type;
}

//무기의 type을 재설정하는 메소드.
void	Weapon::setType(const std::string type)
{
	this->type = type;
}
