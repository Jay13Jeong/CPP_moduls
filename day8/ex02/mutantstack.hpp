#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
	public:
		//생성자.
		MutantStack(): std::stack<T>() {}

		//복사 생성자.
		MutantStack( const MutantStack &m2 ) : std::stack<T>( m2 ) {}
	
		//소멸자.
		~MutantStack() {}

		// 대입연산자 오버로딩.
		MutantStack& operator = ( const MutantStack &m2 )
		{
			if (this == &m2 )
				return (*this);
			this->c = m2.c;
			return (*this);
		}

		//컨테이너의 요소를 수정 가능으로 접근 할 때.
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }

		//컨테이너의 요소를 수정 가능으로 역방향 접근 할 때.
		typedef typename MutantStack<T>::stack::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin() { return this->c.rbegin(); };
		reverse_iterator rend() { return this->c.rend(); };

};

#endif

