#include "ScavTrap.hpp"

//생성자 메소드
ScavTrap::ScavTrap() : ClapTrap()
{
	this->Name = "Anonymous";
	this->HitPoints = 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
	std::cout << "ScavTrap [ " << this->Name << " ] constructed" << std::endl;
}

//생성자 메소드. 매개변수의 이름으로 Name을 설정한다.
ScavTrap::ScavTrap( std::string name ) : ClapTrap( name )
{
	this->Name = name;
	this->HitPoints = 100;
	this->Energy_points = 50;
	this->Attack_damage = 20;
	std::cout << "ScavTrap [ " << this->Name << " ] constructed" << std::endl;
}

//복사 생성자 메소드.
ScavTrap::ScavTrap( const ScavTrap &c2 )
{
	//오버로딩된 대입연산자로 복사 생성.
	*this = c2;
}

//소멸자 메소드.
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap [ " << this->Name << " ] destructed" << std::endl;
}

//대입연산자 '=' 오버로딩 메소드.
ScavTrap & ScavTrap::operator = ( const ScavTrap &c2 )
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
void	ScavTrap::attack( std::string const & target )
{
	std::cout << "ScavTrap " + this->Name + " attack " + target + ", ";
	std::cout << "causing " << this->Attack_damage << " points of damage!";
	std::cout << std::endl;
}

//게이트 키퍼 모드 진입을 알리는 메소드.
void	ScavTrap::guardgate( void )
{
	std::cout << "ScavTrap [ " << this->Name;
	std::cout << " ] has enterred in Gate Kepper mode" << std::endl;
}
