#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm: public Form
{
	private:
		RobotomyRequestForm();
	public:
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( const RobotomyRequestForm &r2 );
		~RobotomyRequestForm();
		RobotomyRequestForm& operator = ( const RobotomyRequestForm &r2 );
		void	execute( Bureaucrat const & executor ) const;
};

#endif
