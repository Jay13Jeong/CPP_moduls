#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club); //A는 생성부터 무기를 가진다.
		bob.attack();
		club.setType("some other type of club"); //무기만 바꿔도 A에 영향준다.
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim"); //B는 생성시 무기없이 만들어진다.
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club"); //무기만 바꿔도 B에 영향준다.
		jim.attack();
	}
}
