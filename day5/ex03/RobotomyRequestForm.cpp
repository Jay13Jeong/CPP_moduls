#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

//디폴트 생성자 메소드.
RobotomyRequestForm::RobotomyRequestForm() {}

//target을 받아서 그 이름으로 양식을 만드는 생성자 메소드.
RobotomyRequestForm::RobotomyRequestForm( std::string target ):
	Form(target, 72, 45) {}

//복사 생성자 메소드.
RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &r2 ): Form(r2) {}

//소멸자 메소드.
RobotomyRequestForm::~RobotomyRequestForm() {}

//대입연산자 '=' 오버로딩 메소드.
RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm &r2 )
{
	//처음에 "Form"부모 클래스로 값을 연산했기때문에 자식클래스로 형태를 다시 캐스팅해준다.
	return (dynamic_cast<RobotomyRequestForm&>(Form::operator=(r2)));
}

//50% 확률로 로봇으로 변하며, 성공여부를 출력하는 메소드.
void	RobotomyRequestForm::execute( Bureaucrat const & executor ) const
{
	//서명이 안되어 있거나, 실행권한이 낮으면 예외처리
	if(this->getisSign() == false)
	{
		throw FormIsNotSigned();
		return ;
	}
	else if (this->getReqExecute() < executor.getGrade())
	{
		throw GradeTooLowException();
		return ;
	}
	int random = 0x9911;
	long long random2 = (long long)&random;
	random2 /= 3;
	if (random2 % 2)
		std::cout << this->getName() << " has been robotomized successfully" << std::endl;
	else
		std::cout << this->getName() << " has not been robotomized successfully" << std::endl;
}
