#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
#include <string>

class Bureaucrat;

class Form
{
	private:
		const std::string	name;			//양식 이름
		bool				is_sign;		//서명여부.
		const int			req_grade;		//서명에 필요한 등급.
		const int			req_execute;	//실행에 필요한 등급.
	public:
		Form();
		Form( std::string name, int req_grade, int req_execute );
		Form( const Form &f2 );
		virtual ~Form();
		Form&				operator = ( const Form &f2 );
		std::string			getName() const;
		bool				getisSign() const;
		int					getReqGrade() const;
		int					getReqExecute() const;
		void				beSigned( Bureaucrat &b );
		virtual void		execute( Bureaucrat const & executor ) const = 0;

		class GradeTooLowException: public std::exception
		{
			virtual	const char * what() const throw();
		};
		class GradeTooHighException: public std::exception
		{
			virtual	const char * what() const throw();
		};
		class FormIsNotSigned: public std::exception
		{
			virtual	const char * what() const throw();
		};
};

std::ostream&		operator << ( std::ostream &out, Form &f );

#endif
