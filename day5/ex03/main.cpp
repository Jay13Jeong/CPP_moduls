#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Intern		intern;
	Bureaucrat	jim("jim", 150);
	Bureaucrat	bob("bob", 1);

	try
	{
		Form* shrubbery = intern.makeForm("shrubbery creation", "s1");
		Form* shrubbery2 = intern.makeForm("shrubbery creation", "s2");
		
		std::cout << *shrubbery << std::endl;
		bob.signForm(*shrubbery);
		bob.executeForm(*shrubbery);
		jim.signForm(*shrubbery2);
		jim.executeForm(*shrubbery2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	try
	{
		Form* robotomy = intern.makeForm("robotomy request", "r1");
		Form* robotomy2 = intern.makeForm("robotomy request", "r2");
		
		std::cout << *robotomy << std::endl;
		bob.signForm(*robotomy);
		bob.executeForm(*robotomy);
		jim.signForm(*robotomy2);
		jim.executeForm(*robotomy2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	try
	{
		Form* president = intern.makeForm("presidential pardon", "s1");
		Form* president2 = intern.makeForm("presidential pardon", "s2");
		
		std::cout << *president << std::endl;
		bob.signForm(*president);
		bob.executeForm(*president);
		jim.executeForm(*president2);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	try
	{
		Form* dummy = intern.makeForm("dummy", "d1");
		
		std::cout << *dummy << std::endl;
		bob.signForm(*dummy);
		bob.executeForm(*dummy);
		jim.executeForm(*dummy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}
