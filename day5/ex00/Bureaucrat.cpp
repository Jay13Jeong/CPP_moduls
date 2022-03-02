#include "Bureaucrat.hpp"

//기본 생성자 메소드.
Bureaucrat::Bureaucrat(): name("anonymous"), grade(150) {}

//매개변수를 받는 생성자 메소드. name상수는 초기화리스트로 초기화.
Bureaucrat::Bureaucrat( const std::string name1, int grade1 ): name(name1)
{
	// 할당하려는 값이 1~150 등급의 범위를 벗어나면 예외처리.
	if (grade1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade = grade1;
}

//복사 생성자 메소드.
Bureaucrat::Bureaucrat( const Bureaucrat &b2 )
{
	*this = b2;
}

//소멸자 메소드.
Bureaucrat::~Bureaucrat() {}

//대입연산자 '=' 오버로딩 메소드.
Bureaucrat& Bureaucrat::operator = ( const Bureaucrat &b2 )
{
	if (this == &b2)
		return (*this);
	//상수멤버변수를 const_cast로 변경한다.
	const_cast<std::string&>(this->name) = b2.name;
	this->grade = b2.grade;
	return (*this);
}

//기본 내장 클래스 exception의 가상함수 what을 오버라이딩 메소드. (등업 예외처리)  
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too High Exception");
}

//기본 내장 클래스 exception의 가상함수 what을 오버라이딩 메소드. (강등 예외처리)
const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low Exception");
}

//이름을 반환하는 메소드.
std::string	Bureaucrat::getName() const
{
	return (this->name);
}

//등급을 반환하는 메소드.
int	Bureaucrat::getGrade() const
{
	return (this->grade);
}

//등급을 내리는 메소드.
void	Bureaucrat::grade_decrement()
{
	//1등급씩 내려가며, 이미 150등급이면 예외를 발생함.
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->grade++;
}

//등급을 올리는 메소드.
void	Bureaucrat::garde_increment()
{
	//1등급씩 올라가며, 이미 1등급이면 예외를 발생함.
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->grade--;
}

//cout '<<' 오버로딩 메소드.
std::ostream& operator << ( std::ostream &out, Bureaucrat &b2 )
{
	out << b2.getName() << ", bureaucrat grade " << b2.getGrade() << std::endl;
	return (out);
}
