#include "FragTrap.hpp"

//생성자 메소드
FragTrap::FragTrap() : ClapTrap()
{
	this->Name = "Anonymous";
	this->HitPoints = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30;
	std::cout << "FragTrap [ " << this->Name << " ] constructed" << std::endl;
}

//생성자 메소드. 매개변수의 이름으로 Name을 설정한다.
FragTrap::FragTrap( std::string Name ) : ClapTrap( Name )
{
	this->Name = Name;
	this->HitPoints = 100;
	this->Energy_points = 100;
	this->Attack_damage = 30;
	std::cout << "FragTrap [ " << this->Name << " ] constructed" << std::endl;
}

//복사 생성자 메소드.
FragTrap::FragTrap( const FragTrap &c2 )
{
	//오버로딩된 대입연산자로 복사 생성.
	*this = c2;
}

//소멸자 메소드.
FragTrap::~FragTrap()
{
	std::cout << "FragTrap [ " << this->Name << " ] destructed" << std::endl;
}

//대입연산자 '=' 오버로딩 메소드.
FragTrap & FragTrap::operator = ( const FragTrap &c2 )
{
	if (this == &c2)
		return *this;
	this->Name = c2.Name;
	this->HitPoints = c2.HitPoints;
	this->Energy_points = c2.Energy_points;
	this->Attack_damage = c2.Attack_damage;
	return *this;
}

//"긍정적 하이파이브를 요청"을 출력하는 메소드.
void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap [ " << this->Name << " ] request a positive high fives" << std::endl;
}
