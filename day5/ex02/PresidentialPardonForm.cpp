#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

//디폴트 생성자 메소드.
PresidentialPardonForm::PresidentialPardonForm() {}

//target을 받아서 그 이름으로 양식을 만드는 생성자 메소드.
PresidentialPardonForm::PresidentialPardonForm( std::string target ):
	Form(target, 25, 5) {}

//복사 생성자 메소드.
PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &p2 ): Form(p2) {}

//소멸자 메소드.
PresidentialPardonForm::~PresidentialPardonForm() {}

//대입연산자 '=' 오버로딩 메소드.
PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm &p2 )
{
	//처음에 "Form"부모 클래스로 값을 연산했기때문에 자식클래스로 형태를 다시 캐스팅해준다.
	return (dynamic_cast<PresidentialPardonForm&>(Form::operator=(p2)));
}

//<target> has been pardoned by Zafod Beeblebrox을 출력하는 메소드.
void	PresidentialPardonForm::execute( Bureaucrat const & executor ) const
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
	std::cout << this->getName();
	std::cout << " has been pardoned by Zafod Beeblebrox.";
	std::cout << std::endl;
}

