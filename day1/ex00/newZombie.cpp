#include "Zombie.hpp"

//좀비클래스로 동적할 할당된 객체를 만들어, 매개변수로 이름을 짓고, 반환하는 함수.
Zombie* newZombie(std::string name)
{
	return (new Zombie(name));
}
