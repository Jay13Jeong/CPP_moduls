#include <iostream>
#include "Base.hpp"

//무작위 Base의 자식클래스 객체를 리턴하는 함수. 
Base * generate(void)
{
	int	dummy = 0x1111;
	long long random = (long long)(&dummy);

	random %= 3;
	if (random == 0)
		return (new A);
	else if (random == 1)
		return (new B);
	return (new C);
}

//매개변수로 Base포인터를 받고, 실제 어떤 자식클래스인지 출력하는 함수.
void identify( Base* p)
{
	//dynamic_cast로 다운 캐스팅 해준다.
	//실패시 null을 리턴하는 것으로 맞는 자료형을 찾는다.
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

//매개변수로 Base 참조를 받고, 실제 어떤 자식클래스인지 출력하는 함수.
void identify(Base& p)
{
	//try catch안쓰면 abort발생한다.
	try
	{
		A(dynamic_cast<A&>(p));
		std::cout << "A" << std::endl;
	}catch(std::exception & e){}

	try
	{
		B(dynamic_cast<B&>(p));
		std::cout << "B" << std::endl;
	}catch(std::exception & e){}

	try
	{
		C(dynamic_cast<C&>(p));
		std::cout << "C" << std::endl;
	}catch(std::exception & e){}
}

int main()
{
	Base *base = generate();

	identify(base);
	identify(*base);
	delete base;

	return (0);
}
