#include "Zombie.hpp"

/* 좀비무리를 n만큼 생성하고 받아온 이름을 붙이고, */
/* announce하고, 첫번째 좀비의 주소를 반환하는 함수. */
Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombies = new Zombie[N];

	for (int i = 0; i < N; i++)
	{
		zombies[i].set_name(name + std::to_string(i));
		zombies[i].announce();
	}
	return (zombies);
}
