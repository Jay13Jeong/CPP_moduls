#include "../includes/Animal.hpp"

//생성자 메소드.
Animal::Animal()
{
	this->type = "Animal";
	std::cout << "Animal constructed" << std::endl;
}

//복사 생성자 메소드.
Animal::Animal( const Animal &a2 )
{
	*this = a2;
	std::cout << "Animal copy constructed" << std::endl;
}

//소멸자 메소드.
Animal::~Animal()
{
	std::cout << "Animal destructed" << std::endl;
}

//대입연산자 '=' 오버로딩 메소드.
Animal& Animal::operator = ( const Animal &a2 )
{
	if (this == &a2) //기존주소와 동일한 주소가 들어오면 바꾸지 않는다.
		return (*this);
	this->type = a2.type;
	return (*this);
}

//동물의 종류를 반환하는 메소드.
std::string	Animal::getType() const
{
	return (this->type);
}

//동물의 소리를 출력하는 메소드.
void		Animal::makeSound() const
{
	std::cout << "Animal sound" << std::endl;
}
