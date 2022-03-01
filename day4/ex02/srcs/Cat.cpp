#include "../includes/Cat.hpp"

//생성자 메소드.
Cat::Cat()
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "Cat constructed" << std::endl;
}

//복사 생성자 메소드.
Cat::Cat( const Cat &c2 )
{
	*this = c2;
	std::cout << "Cat copy constructed" << std::endl;
}

//소멸자 메소드.
Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructed" << std::endl;
}

//대입연사자 '=' 오버로딩 메소드.
Cat& Cat::operator = ( const Cat &c2 )
{
	if (this == &c2)
		return (*this);
	this->type = c2.type;
	*(this->brain) = *(c2.brain);
	return (*this);
}

//고양이 소리 출력 메소드.
void	Cat::makeSound() const
{
	std::cout << "Cat sound" << std::endl;
}
