#include "../includes/WrongAnimal.hpp"

//생성자 메소드.
WrongAnimal::WrongAnimal()
{
	this->type = "WrongAnimal";
	std::cout << "Wrong Animal constructed" << std::endl;
}

//복사 생성자 메소드.
WrongAnimal::WrongAnimal( const WrongAnimal &w2 )
{
	*this = w2;
	std::cout << "Wrong Animal constructed" << std::endl;
}

//소멸자 메소드.
WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructed" << std::endl;
}

//대입연산자 '=' 오버로딩 메소드.
WrongAnimal& WrongAnimal::operator = ( const WrongAnimal &w2 )
{
	if (this == &w2)
		return (*this);
	this->type = w2.type;
	return (*this);
}

//엉뚱한 동물의 종류를 반환하는 메소드.
std::string	WrongAnimal::getType() const
{
	return (this->type);
}

//엉뚱한 동물의 소리를 출력하는 메소드.
void		WrongAnimal::makeSound() const
{
	std::cout << "Wrong Animal sound" << std::endl;
}
