#include "Fixed.hpp"

//기본 생성자 메소드.
Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point_value = 0; //고정 소수점 값 0으로 초기화
}

//int형을 고정 소수점 값으로 저장하는 메소드.
Fixed::Fixed( const int n )
{
	std::cout << "Int constructor called" << std::endl;
	//마지막 8비트는 소수점 뒤의 수를 위해 0으로 채워둔다.
	this->fixed_point_value = ( n << this->bits );
}

//float값을 고정 소수점 값으로 저장하는 메소드.
Fixed::Fixed( const float f )
{
	std::cout << "Float constructor called" << std::endl;
	//float은 비트연산자가 불가능하므로 소수점 뒤 8비트만큼만(1 << 8) 정수쪽으로 곱셈으로 당기고
	//roundf로 나머지 소수점은 버리고 정수로 저장한다.
	this->fixed_point_value = (int)(roundf(f * (1 << this->bits)));
}

//복사 생성자 메소드.
Fixed::Fixed( const Fixed &f2 )
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixed_point_value = f2.fixed_point_value;
}

//소멸자 메소드.
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

//'='대입연산자 오버로드
Fixed& Fixed::operator=(const Fixed &f2)
{
	std::cout << "Assignation operator called" << std::endl;
	this->fixed_point_value = f2.fixed_point_value;
	return *this;
}

//고정소수점 값 반환 메소드.
int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_point_value);
}

//고정 소수점 값을 재설정하는 메소드.
void Fixed::setRawBits( int const raw )
{
	this->fixed_point_value = raw;
}

//고정 소수점 값을 float으로 반환 메소드.
float	Fixed::toFloat() const
{
	//정수쪽으로 가져왔던 소수 8비트만큼을 다시 소수점 뒤로 밀어서 float으로 반환한다.
	return (((float)this->fixed_point_value) / (1 << this->bits));
}

//고정 소수점 값을 int로 반환 메소드.
int Fixed::toInt() const
{
	//소수점 값이 들어있는 8비트를 지우고 int형으로 반환한다.
	return ((int)(this->fixed_point_value >> this->bits));
}

//cout의 "<<" 오버로드
std::ostream& operator<<(std::ostream &out, const Fixed &a)
{
	//이미 cout에 float에 대해서 오버로드가 있으므로 float으로 바꾼 고정소수값을 넣는다.
	out << a.toFloat();
	return (out);
}
