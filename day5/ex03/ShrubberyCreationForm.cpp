#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

//디폴트 생성자 메소드.
ShrubberyCreationForm::ShrubberyCreationForm() {}

//target을 받아서 그 이름으로 양식을 만드는 생성자 메소드.
ShrubberyCreationForm::ShrubberyCreationForm( std::string target ):
	Form(target, 145, 137) {}

//복사 생성자 메소드.
ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &s2 ): Form(s2) {}

//소멸자 메소드.
ShrubberyCreationForm::~ShrubberyCreationForm() {}

//대입연산자 '=' 오버로딩 메소드.
ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm &s2 )
{
	//처음에 "Form"부모 클래스로 값을 연산했기때문에 자식클래스로 형태를 다시 캐스팅해준다.
	return (dynamic_cast<ShrubberyCreationForm&>(Form::operator=(s2)));
}

//파일 생성 실패 예외처리 오버라이딩.
const char* ShrubberyCreationForm::FileCannotCreate::what() const throw()
{
	return ("File Cannot Create");
}

//ascii tree로 양식을 만드는 메소드.
void	ShrubberyCreationForm::execute( Bureaucrat const & executor ) const
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
	//실행가능하면 ascii trees를 그려서 파일에 저장한다. 이미 있다면 trunc로 덮어씌우기.
	std::ofstream	write_file(this->getName() + "_shrubbery", std::ofstream::out | std::ofstream::trunc);
	
	//입출력이 가능한지 확인하고, 실패시 예외처리한다.
	if (!write_file.is_open() || write_file.bad())
		throw FileCannotCreate();
	write_file <<"\
                   ,@@@@@@@,\n\
           ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
        ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
       ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n\
       %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
       %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n\
       `&%\\ ` /%&'    |.|        \\ '|8'\n\
           |o|        | |         | |\n\
           |.|        | |         | |\n\
        \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
	write_file.close();
}
