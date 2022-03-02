#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm: public Form
{
	private:
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( const ShrubberyCreationForm &s2 );
		~ShrubberyCreationForm();
		ShrubberyCreationForm& operator = ( const ShrubberyCreationForm &s2 );
		void	execute( Bureaucrat const & executor ) const;

		class FileCannotCreate: public std::exception
		{
			virtual	const char * what() const throw();
		};
};

#endif
