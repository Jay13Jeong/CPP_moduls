#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm: public Form
{
	private:
		PresidentialPardonForm();
	public:
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( const PresidentialPardonForm &p2 );
		~PresidentialPardonForm();
		PresidentialPardonForm& operator = ( const PresidentialPardonForm &p2 );
		void	execute( Bureaucrat const & executor ) const;
};

#endif
