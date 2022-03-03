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
	int i = std::find(lvl_list, lvl_list + 4, level) - lvl_list;

	switch (i)
	{
		case 0: act = &Karen::debug;break;
		case 1: act = &Karen::info;break;
		case 2: act = &Karen::warning;break;
		case 3: act = &Karen::error;break;
		default:
			return;
	}
	(this->*act)();
}
