#ifndef KAREN_HPP
#define KAREN_HPP

#include <iostream>
#include <string>

class Karen
{
	private:
		void	debug( void );
		void	info( void );
		void	warning( void );
		void	error( void );
		/* 멤버함수포인터 메소드 */
		/* 반환타입, 클래스::멤버함수 이름, (매개변수)*/
		void	(Karen:: *act) (void);
	public:
		void	complain( std::string level );
};

#endif
