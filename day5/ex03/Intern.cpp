#include "Intern.hpp"

//생성자 메소드.
Intern::Intern() {}

//복사 생성자 메소드.
Intern::Intern( const Intern &i2 )
{
	*this = i2;
}

//소멸자 메소드.
Intern::~Intern() {}

//대입연산자 오버로딩 메소드
Intern& Intern::operator = ( const Intern &i2 )
{
	if (this == &i2)
		return (*this);
	return (*this);
}

//양식을 찾지 못했을 때 예외처리 오버라이딩 메소드.
const char* Intern::FormCanNotFound::what() const throw()
{
	return ("Form Can Not Found");
}

//양식의 종류와 지칭할 이름을 받아 새로운 양식을 만드는 메소드.
Form*	Intern::makeForm( std::string form_type, std::string target )
{
	std::string	lst[] = { "shrubbery creation", "robotomy request", "presidential pardon" };
	int	i = -1;

	for (int k = 0; k < 4; k++)
		if (form_type == lst[k])
		{
			i = k;
			break;
		}

	switch(i)
	{
		case 0:
			std::cout << "Intern creates " << lst[i] << std::endl;
			return new ShrubberyCreationForm(target);
		case 1:
			std::cout << "Intern creates " << lst[i] << std::endl;
			return new RobotomyRequestForm(target);
		case 2:
			std::cout << "Intern creates " << lst[i] << std::endl;
			return new PresidentialPardonForm(target);
		default:
			throw(FormCanNotFound());
	}
	return (NULL);
}
