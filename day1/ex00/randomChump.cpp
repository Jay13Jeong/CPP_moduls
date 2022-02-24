#include "Zombie.hpp"

//좀비객체를 생성하고, 그 좀비가 announce한 뒤에 소멸시키는 함수.
void randomChump(std::string name)
{
	Zombie *zombie;
	
	zombie = newZombie(name); //좀비클래스 포인터에 동적할당.
	zombie->announce(); //만들어진 객체가 announce한다.
	delete zombie; //사용이끝나면 동적할당된 객체를 소멸시킨다.
}
