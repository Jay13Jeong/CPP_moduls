#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Bureaucrat
{
	private:
		const std::string	name;
		int					grade;
	public:
		Bureaucrat();
		Bureaucrat( const std::string name1, int grade1 );
		Bureaucrat( const Bureaucrat &b2 );
		~Bureaucrat();
		Bureaucrat& operator = ( const Bureaucrat &b2 );
		std::string		getName() const;
		int				getGrade() const;
		void			garde_increment();
		void			grade_decrement();
		void			signForm( Form &f );

		//Bureaucrat전용 exception을 상속받는 예외처리 클래스.  
		class GradeTooLowException: public std::exception
		{
			virtual const char* what() const throw();
		};
		class GradeTooHighException: public std::exception
		{
			virtual const char* what() const throw();
		};
};

std::ostream& operator << ( std::ostream &out, Bureaucrat &b2 );

#endif
