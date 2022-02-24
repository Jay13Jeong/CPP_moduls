#include "Zombie.hpp"

Zombie::Zombie(void) {} //기본생성자

//이름 매개변수를 객체에 할당하는, 좀비객체 생성자 함수.
Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << this->name << " zombie constructed";
	std::cout << std::endl;
}

//객체의 이름과 함께 BraiiiiiiinnnzzzZ...라고 출력하는 함수.
void Zombie::announce(void) const
{
	std::cout << "<" + this->name + "> BraiiiiiiinnnzzzZ...";
	std::cout << std::endl;
}

//좀비객체에 매개변수로 가져온 이름을 할당하는 함수.
void Zombie::set_name(const std::string name)
{
	this->name = name;
}

//좀비객체 소멸자 함수.
Zombie::~Zombie(void)
{
	std::cout << this->name << " zombie destructed";
	std::cout << std::endl;
}
