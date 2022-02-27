#include "Fixed.hpp"

//기본 생성자 메소드.
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point_value = 0; //고정소수점 값을 0으로 초기화한다.
}

//복사 생성자. 깊은복사를 위해 매개변수를 참조변수로 받음
Fixed::Fixed(const Fixed &f2)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixed_point_value = f2.getRawBits();
}

//소멸자 메소드.
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//'='대입연산자 오버로드 메소드. 임시복사본 방지를 위해 레퍼런스로 반환.
Fixed& Fixed::operator=(const Fixed &f2)
{
	std::cout << "Assignation operator called" << std::endl;
	this->fixed_point_value = f2.getRawBits();
	return ( *this );
}

//고정소수점 값을 반환하는 메소드.
int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return ( this->fixed_point_value );
}

//고정소수점 값을 재설정하는 메소드.
void Fixed::setRawBits( int const raw )
{
	this->fixed_point_value = raw;
}
