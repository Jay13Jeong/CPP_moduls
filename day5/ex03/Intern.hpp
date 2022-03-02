#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
	public:
		Intern();
		Intern( const Intern &i2 );
		~Intern();
		Intern& operator = ( const Intern &i2 );
		Form*	makeForm( std::string form_type, std::string target );

		class FormCanNotFound: public std::exception
		{
			virtual	const char * what() const throw();
		};
};

#endif
