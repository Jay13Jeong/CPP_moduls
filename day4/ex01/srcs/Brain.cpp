#include "../includes/Brain.hpp"

//생성자 메소드.
Brain::Brain()
{
	std::cout << "Brain constructed" << std::endl;
}

//복사 생성자 메소드.
Brain::Brain( const Brain &b2 )
{
	*this = b2;
	std::cout << "Brain copy constructed" << std::endl;
}

//소멸자 메소드.
Brain::~Brain()
{
	std::cout << "Brain destructed" << std::endl;
}

//대입연산자 '=' 오버로딩 메소드. 깊은복사.
Brain& Brain::operator = ( const Brain &b2 )
{
	if (this == &b2)
		return (*this);
	for (int i = 0; i < 100; i++)
		this->ideas[i] = b2.ideas[i];
	return (*this);
}
