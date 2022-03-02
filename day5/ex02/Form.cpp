#include "Form.hpp"
#include "Bureaucrat.hpp"

//디폴트 생성자 메소드.
Form::Form(): name("No Title"), is_sign(false), req_grade(150), req_execute(150) {}

//매개변수를 받는 생성자 메소드. 초기화리스트로 상수 멤버변수를 초기화한다.
Form::Form( std::string name1, int req_grade1, int req_execute1 ):
	name(name1), req_grade(req_grade1), req_execute(req_execute1)
{
	//1 ~ 150 범위를 넘어가면 예외처리.
	if (req_grade < 1 || req_execute < 1)
		throw Form::GradeTooHighException();
	if ( req_grade > 150 || req_execute > 150)
		throw Form::GradeTooLowException();
	else
		this->is_sign = false; //기본 초기값은 false로 한다.
}

//복사 생성자 메소드.
Form::Form( const Form &f2 ):
	name(f2.name), req_grade(f2.req_grade), req_execute(f2.req_execute)
{
	*this = f2;
}

//소멸자 메소드.
Form::~Form() {}

//대입연산자 '=' 오버로딩 메소드.
Form& Form::operator = ( const Form &f2 )
{
	if (this == &f2)
		return (*this);
	const_cast<std::string&>(this->name) = f2.getName();
	this->is_sign = f2.is_sign;
	const_cast<int&>(this->req_grade) = f2.getReqGrade();
	const_cast<int&>(this->req_execute) = f2.getReqExecute();
	return (*this);
}

//기본 내장 클래스 exception의 가상함수 what을 오버라이딩 메소드. (등급 초과 예외처리)
const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade is Too High");
}

//기본 내장 클래스 exception의 가상함수 what을 오버라이딩 메소드. (등급 미달 예외처리)
const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is Too Low");
}

//이름을 반환하는 메소드
std::string	Form::getName() const
{
	return (this->name);
}

//사인여부를 반환하는 메소드.
bool	Form::getisSign() const
{
	return (this->is_sign);
}

//서명에 필요한 등급을 반환하는 메소드.
int	Form::getReqGrade() const
{
	return (this->req_grade);
}

//실행에 필요한 등급을 반환하는 메소드.
int	Form::getReqExecute() const
{
	return (this->req_execute);
}

//등급을 심사해서 서명하는 메소드.
void		Form::beSigned( Bureaucrat &b )
{
	//서명 필요 등급보다 낮으면 예외처리하고, 이상이면 서명한다.
	if (b.getGrade() > this->req_grade)
		throw  Form::GradeTooLowException();
	else
		this->is_sign = true;
}

//cout '<<' 오버로딩 메소드.
std::ostream& operator << ( std::ostream &out, Form &f )
{
	out << "[ Form ]" << f.getName() << ", Form is ";
	out << (f.getisSign() == true ? "signed" : "not signed");
	out << ", required grade is " << f.getReqGrade();
	out << ", required execute grade is " << f.getReqExecute();
	out << std::endl;
	return (out);
}

//서명 안됨을 예외처리하는 오버라이딩 메소드.
const char* Form::FormIsNotSigned::what() const throw()
{
	return ("Form is not signed");
}