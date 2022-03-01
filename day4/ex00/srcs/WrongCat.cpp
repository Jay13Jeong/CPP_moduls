#include "../includes/WrongCat.hpp"

//생성자 메소드.
WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "Wrong Cat constructed" << std::endl;
}

//복사 생성자 메소드.
WrongCat::WrongCat( const WrongCat &w2 )
{
	*this = w2;
	std::cout << "Wrong Cat constructed" << std::endl;
}

//소멸자 메소드.
WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructed" << std::endl;
}

//대입연산자 '=' 오버로딩 메소드.
WrongCat& WrongCat::operator = ( const WrongCat &w2 )
{
	if (this == &w2)
		return (*this);
	this->type = w2.type;
	return (*this);
}

//엉뚱한 고양이의 소리를 출력하는 메소드.
void	WrongCat::makeSound() const
{
	std::cout << "Wrong Cat sound" << std::endl;
}
