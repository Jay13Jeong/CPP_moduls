#include "Fixed.hpp"

//기본 생성자 메소드.
Fixed::Fixed()
{
	this->fixed_point_value = 0; //고정 소수점 값 0으로 초기화
}

//int형을 고정 소수점 값으로 저장하는 메소드.
Fixed::Fixed( const int n )
{
	//마지막 8비트는 소수점 뒤의 수를 위해 0으로 채워둔다.
	this->fixed_point_value = ( n << this->bits );
}

//float값을 고정 소수점 값으로 저장하는 메소드.
Fixed::Fixed( const float f )
{
	//float은 비트연산자가 불가능하므로 소수점 뒤 8비트만큼만(1 << 8) 정수쪽으로 곱셈으로 당기고
	//roundf로 나머지 소수점은 버리고 정수로 저장한다.
	this->fixed_point_value = (int)(roundf(f * (1 << this->bits)));
}

//복사 생성자 메소드.
Fixed::Fixed( const Fixed &f2 )
{
	this->fixed_point_value = f2.fixed_point_value;
}

//소멸자 메소드.
Fixed::~Fixed() {}

//고정소수점 값 반환 메소드.
int Fixed::getRawBits( void ) const
{
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

//'='대입연산자 오버로드
Fixed& Fixed::operator = (const Fixed &f2)
{
	this->fixed_point_value = f2.fixed_point_value;
	return *this;
}

//더하기'+'오버로드
Fixed Fixed::operator + (const Fixed &f2) const
{
	Fixed temp;
	temp.setRawBits(this->getRawBits() + f2.getRawBits());
	return (temp);
}

//빼기'-'오버로드
Fixed Fixed::operator - (const Fixed &f2) const
{
	Fixed temp;
	temp.setRawBits(this->getRawBits() - f2.getRawBits());
	return (temp);
}

//곱하기'*'오버로드
Fixed Fixed::operator * (const Fixed &f2) const
{
	return (Fixed(this->toFloat() * f2.toFloat()));
}

//나누기'/'오버로드
Fixed Fixed::operator / (const Fixed &f2) const
{
	return (Fixed(this->toFloat() / f2.toFloat()));
}

//전위 연산자 "++a" 오버로드
Fixed& Fixed::operator ++ ( void )
{
	++(this->fixed_point_value);
	return (*this);
}

//전위 연산자 "--a" 오버로드
Fixed& Fixed::operator -- ( void )
{
	--(this->fixed_point_value);
	return (*this);
}

//후위 연산자 "a++" 오버로드
Fixed Fixed::operator ++ ( int )
{
	//복사연산자로 ++연산 전의 객체를 복사해서 반환한다.
	Fixed temp(*this);
	++(this->fixed_point_value);
	return (temp);
}

//후위 연산자 "a--" 오버로드
Fixed Fixed::operator -- ( int )
{
	//복사연산자로 --연산 전의 객체를 복사해서 반환한다.
	Fixed temp(*this);
	--(this->fixed_point_value);
	return (temp);
}

//'>'오버로드
bool Fixed::operator > ( const Fixed &f2) const
{
	return (this->getRawBits() > f2.getRawBits());
}

//'<'오버로드
bool Fixed::operator < ( const Fixed &f2) const
{
	return (this->getRawBits() < f2.getRawBits());
}

//'>='오버로드
bool Fixed::operator >= ( const Fixed &f2) const
{
	return (this->getRawBits() >= f2.getRawBits());
}

//'<='오버로드
bool Fixed::operator <= ( const Fixed &f2) const
{
	return (this->getRawBits() <= f2.getRawBits());
}

//'=='오버로드
bool Fixed::operator == ( const Fixed &f2) const
{
	return (this->getRawBits() == f2.getRawBits());
}

//'!='오버로드
bool Fixed::operator != ( const Fixed &f2) const
{
	return (this->getRawBits() != f2.getRawBits());
}

//둘중 작은 값의 참조를 반환하는 메소드.
Fixed& Fixed::min(Fixed &f1, Fixed &f2)
{
	return (f1 < f2 ? f1 : f2);
}

//둘중 작은 값의 상수 참조를 반환하는 메소드. (좀더 안정적)
const Fixed& Fixed::min(const Fixed &f1, const Fixed &f2)
{
	return (f1 < f2 ? f1 : f2);
}

//둘중 큰 값의 참조를 반환하는 메소드.
Fixed& Fixed::max(Fixed &f1, Fixed &f2)
{
	return (f1 > f2 ? f1 : f2);
}

//둘중 큰 값의 상수 참조를 반환하는 메소드. (좀더 안정적)
const Fixed& Fixed::max(const Fixed &f1, const Fixed &f2)
{
	return (f1 > f2 ? f1 : f2);
}

//cout의 "<<" 오버로드
std::ostream& operator << (std::ostream &out, const Fixed &a)
{
	out << a.toFloat();
	return (out);
}

