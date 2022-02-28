#include "ClapTrap.hpp"

//생성자 메소드
ClapTrap::ClapTrap()
{
	this->Name = "Anonymous";
	this->HitPoints = 10;
	this->Energy_points = 10;
	this->Attack_damage = 0;
	std::cout << "ClapTrap [ " << this->Name << " ] constructed" << std::endl;
}

//생성자 메소드. 매개변수의 이름으로 Name을 설정한다.
ClapTrap::ClapTrap( std::string name )
{
	this->Name = name;
	this->HitPoints = 10;
	this->Energy_points = 10;
	this->Attack_damage = 0;
	std::cout << "ClapTrap [ " << this->Name << " ] constructed" << std::endl;
}

//복사 생성자 메소드.
ClapTrap::ClapTrap( const ClapTrap &c2 )
{
	//오버로딩된 대입연산자로 복사 생성.
	*this = c2;
}

//소멸자 메소드.
ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap [ " << this->Name << " ] destructed" << std::endl;
}

//대입연산자 '=' 오버로딩 메소드.
ClapTrap& ClapTrap::operator = ( const ClapTrap &c2 )
{
	if (this == &c2)
		return *this;
	this->Name = c2.Name;
	this->HitPoints = c2.HitPoints;
	this->Energy_points = c2.Energy_points;
	this->Attack_damage = c2.Attack_damage;
	return *this;
}

//공격 메소드.
void	ClapTrap::attack( std::string const & target )
{
	std::cout << "ClapTrap " + this->Name + " attack " + target + ", ";
	std::cout << "causing " << this->Attack_damage << " points of damage!";
	std::cout << std::endl;
}

//매개변수만큼 피격을 업데이트하는 메소드.
void	ClapTrap::takeDamage( unsigned int amount )
{
	bool is_live = (this->HitPoints > 0);
	this->HitPoints -= amount;
	if (this->HitPoints < 0)
		this->HitPoints = 0;
	if (is_live) //살아있던 상태에서 피격을 받으면 받은 피해와 남은 피해를 출력.
	{
		std::cout << "ClapTrap " + this->Name + " take " << amount << " damage ";
		std::cout << "(HitPoint : " << this->HitPoints << " point left)"; 
		std::cout << std::endl;
	}
	if (this->HitPoints == 0) //생명력이 0이면 죽음을 알림.
		std::cout << "ClapTrap " << this->Name << " is Dead." << std::endl;
}

//매개변수만큼 피격을 회복하는 메소드.
void	ClapTrap::beRepaired( unsigned int amount )
{
	//살아 있는 상태에서만 회복가능하며, 죽으면 회복 불가능 메세지가 출력된다.
	if (this->HitPoints == 0)
		std::cout << "ClapTrap ** Can't repaire, " << this->Name << " is Dead. **" << std::endl;
	else
	{
		this->HitPoints += amount;
		std::cout << "ClapTrap " << this->Name << " repaired " << amount;
		std::cout << " (HitPoint : " << this->HitPoints << " point left)";
		std::cout << std::endl;
	}
}
