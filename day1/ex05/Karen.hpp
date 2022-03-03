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
		/* 4가지의 멤버함수ptr을 담을 수 있는 배열 */
		/* 반환타입, 클래스::멤버함수 이름, (매개변수)*/
		void	(Karen:: *act[4]) (void);
	public:
		void	complain( std::string level );
};

#endif
