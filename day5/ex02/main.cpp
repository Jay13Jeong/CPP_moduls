#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat	jim("jim", 150);
	Bureaucrat	bob("bob", 1);

	try
	{
		ShrubberyCreationForm shrubbery = ShrubberyCreationForm("shrubbery1");
		ShrubberyCreationForm shrubbery2 = ShrubberyCreationForm("shrubbery2");
		
		std::cout << shrubbery << std::endl;
		bob.signForm(shrubbery);
		bob.executeForm(shrubbery);
		jim.signForm(shrubbery2);
		jim.executeForm(shrubbery2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	try
	{
		RobotomyRequestForm robotomy = RobotomyRequestForm("robotomy1");
		RobotomyRequestForm robotomy2 = RobotomyRequestForm("robotomy2");
		
		std::cout << robotomy << std::endl;
		bob.signForm(robotomy);
		bob.executeForm(robotomy);
		jim.signForm(robotomy2);
		jim.executeForm(robotomy2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	try
	{
		PresidentialPardonForm president = PresidentialPardonForm("president1");
		PresidentialPardonForm president2 = PresidentialPardonForm("president2");
		
		std::cout << president << std::endl;
		bob.signForm(president);
		bob.executeForm(president);
		jim.executeForm(president2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}
