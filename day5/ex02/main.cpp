#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
// #include <stdlib.h>

int main()
{
	Bureaucrat	jim("jim", 150);
	Bureaucrat	bob("bob", 1);

	try
	{
		ShrubberyCreationForm shrubbery = ShrubberyCreationForm("shrubbery1");
		
		std::cout << shrubbery << std::endl;
		bob.executeForm(shrubbery);
		jim.executeForm(shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	try
	{
		RobotomyRequestForm robotomy = RobotomyRequestForm("robotomy1");
		
		std::cout << robotomy << std::endl;
		bob.executeForm(robotomy);
		jim.executeForm(robotomy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	try
	{
		PresidentialPardonForm president = PresidentialPardonForm("president1");
		
		std::cout << president << std::endl;
		bob.executeForm(president);
		jim.executeForm(president);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}
