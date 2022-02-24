#include "Karen.hpp"

void	Karen::debug( void )
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love to get extra bacon for my ";
	std::cout << "7XL-double-cheese-triple-pickle-";
	std::cout << "special-ketchup burger. I just love it!\n";
	std::cout << std::endl;
}

void	Karen::info( void )
{
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon cost";
	std::cout << " more money. You don’t put enough! ";
	std::cout << "If you did I would not have to ask for it!\n";
	std::cout << std::endl;
}

void	Karen::warning( void )
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon ";
	std::cout << "for free. I’ve been coming here for years ";
	std::cout << "and you just started working here last month.\n";
	std::cout << std::endl;
}

void	Karen::error( void )
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable, I want to speak ";
	std::cout << "to the manager now.\n";
	std::cout << std::endl;
}

//switch문으로 해당레벨 이상의 모든 정보를 출력하는 메소드.
void	Karen::complain_switch(int i)
{
	//각 case에 브레이크를 걸지않으면 default까지 전부 돌아간다.
	switch (i)
	{
		case 0: Karen::debug();
		case 1: Karen::info();
		case 2: Karen::warning();
		case 3: Karen::error();break;
		default:
		{
			std::cout << "[ Probably complaining about ";
			std::cout << "insignificant problems ]" << std::endl;
			break;
		}
	}
	exit(0);
}

//매개변수로 항의레벨을 받고 해당레벨이상의 모든 행동을 출력하는 메소드.
void	Karen::filter( std::string level )
{
	std::string lvl_list[] = {"debug", "info", "warning", "error"};

	for (int i = 0; i < 4; i++)
		if (level == lvl_list[i])
			this->complain_switch(i);
	//만약 위 4가지 행동중에 해당사항없으면 기본문구를 출력한다.
	this->complain_switch(999);
}
