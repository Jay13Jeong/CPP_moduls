#include "Karen.hpp"

//private 메소드1.
void	Karen::debug( void )
{
	std::cout << "I love to get extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-";
	std::cout << "special-ketchup burger. I just love it!";
	std::cout << std::endl;
}

//private 메소드2.
void	Karen::info( void )
{
	std::cout << "I cannot believe adding extra bacon cost";
	std::cout << " more money. You don’t put enough! ";
	std::cout << "If you did I would not have to ask for it!";
	std::cout << std::endl;
}

//private 메소드3.
void	Karen::warning( void )
{
	std::cout << "I think I deserve to have some extra bacon ";
	std::cout << "for free. I’ve been coming here for years ";
	std::cout << "and you just started working here last month.";
	std::cout << std::endl;
}

//private 메소드4.
void	Karen::error( void )
{
	std::cout << "This is unacceptable, I want to speak ";
	std::cout << "to the manager now.";
	std::cout << std::endl;
}

//매개변수에 해당하는 명령을  포인터함수를 이용해서 private메소드를 실해하는 메소드.
void	Karen::complain( std::string level )
{
	
	std::string lvl_list[] = {"debug", "info", "warning", "error"};

	/* 각 배열에 private 메소드의 주소를 넣는다. */
	this->act[0] = &Karen::debug;
	this->act[1] = &Karen::info;
	this->act[2] = &Karen::warning;
	this->act[3] = &Karen::error;
	/* 매개변수에 해당하는 행동을 포인터와 연결된 멤버함수로 실행*/
	for (int i = 0; i < 4; i++)
		if (level == lvl_list[i])
		{
			(this->*act[i])();	
			return ;
		}
}
