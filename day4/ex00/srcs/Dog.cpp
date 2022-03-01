#include "../includes/Dog.hpp"

//생성자 메소드.
Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog constructed" << std::endl;
}

//복사 생성자 메소드.
Dog::Dog( const Dog &d2 )
{
	*this = d2;
	std::cout << "Dog constructed" << std::endl;
}

//소멸자 메소드.
Dog::~Dog()
{
	std::cout << "Dog Destructed" << std::endl;
}

//대입연산자 '=' 오버로딩 메소드.
Dog & Dog::operator = ( const Dog &d2 )
{
	if (this == &d2 )
		return (*this);
	this->type = d2.type;
	return (*this);
}

//개의 소리를 출력하는 메소드.
void	Dog::makeSound() const
{
	std::cout << "Dog sound" << std::endl;
}
