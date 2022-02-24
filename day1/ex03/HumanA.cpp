#include "HumanA.hpp"

//생성자 메소드. 클래스의 참조변수는 무조건 생성자의 "초기화리스트"로만 값을 얻는다.
HumanA::HumanA(std::string name1, Weapon &weapon1): name(name1), weapon(weapon1){}

//소멸자 메소드.
HumanA::~HumanA(void)
{
	std::cout << "HumanA Destructed" << std::endl;
}

//공격 메소드.
void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with his ";
	std::cout << this->weapon.getType() << std::endl;
}
