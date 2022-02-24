#include "Zombie.hpp"

//이름 매개변수를 객체에 할당하는, 좀비객체 생성자 함수.
Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << this->name << " constructed";
	std::cout << std::endl;
}

//객체의 이름과 함께 BraiiiiiiinnnzzzZ...라고 출력하는 함수.
void Zombie::announce(void)
{
	std::cout << "<" + this->name + "> BraiiiiiiinnnzzzZ...";
	std::cout << std::endl;
}

//좀비객체 소멸자 함수.
Zombie::~Zombie(void)
{
	std::cout << this->name << " destructed";
	std::cout << std::endl;
}
