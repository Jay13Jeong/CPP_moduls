#include "Bureaucrat.hpp"

int main()
{
	//등급올리기 try catch.
	try
	{
		Bureaucrat jim("jim", 2);

		std::cout << jim;
		jim.garde_increment();
		std::cout << jim;
		jim.garde_increment();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	//등급내리기 try catch.
	try
	{
		Bureaucrat bob("bob", 149);

		std::cout << bob;
		bob.grade_decrement();
		std::cout << bob;
		bob.grade_decrement();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	//선언 할 수 있는 등급 최소치를 넘었을 때
	try
	{
		Bureaucrat bob("bob", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	//선언 할 수 있는 등급 최대치를 넘었을 때 
	try
	{
		Bureaucrat jim("jim", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Bureaucrat *b = new Bureaucrat("a", 5);
	// std::cout << b->getName() << b->getGrade() << std::endl;
	// Bureaucrat *c = new Bureaucrat("b",10);
	// *b = *c;
	// std::cout << b->getName() << b->getGrade() << std::endl;
}
