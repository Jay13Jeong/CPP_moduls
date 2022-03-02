#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	//객체 선언시 범위 초과 예외처리.
	try
	{
		Form apple("apple", 0, 30);
		std::cout << apple << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std:: endl;

	//서명시 필요등급 보다 낮을 때 예외처리
	try
	{
		Form		banana("banana", 30, 20);
		Bureaucrat	jim("jim", 100);

		//cout을 오버로딩해서 Form 출력  
		std::cout << banana << std::endl;

		jim.signForm(banana);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std:: endl;

	//정상적으로 서명이 되고, 그상태를 Bureaucrat에서 출력
	try
	{
		Form		apple("apple", 120, 20);
		Bureaucrat	bob("bob", 100);

		bob.signForm(apple);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std:: endl;

}
