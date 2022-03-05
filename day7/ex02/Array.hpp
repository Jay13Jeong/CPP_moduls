#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>
#include <string>

template <typename T>
class Array
{
	private:
		T				*array;		//배열
		unsigned int	arr_size;	//배열의 크기
	public:
		//빈배열 T객체를 갖는 디폴트 생성자.
		Array(): array(new T[0]), arr_size(0){};
		
		//매개변수 n크기의 배열 T객체를 갖는 생성자.
		Array( unsigned int n ): array(new T[n]), arr_size(n){};
		
		//복사 생성자.
		Array( const Array &a2 )
		{
			this->array = new T[a2.size()];
			this->arr_size = a2.size();
			for (unsigned int i = 0; i < (a2.size()); i++)
				this->array[i] = a2.array[i];
		};
		
		//소멸자.
		~Array(){ delete[] this->array; };
		
		//대입연산자 오버로딩.
		Array& operator = ( const Array &a2 )
		{
			if (this == &a2)
				return (*this);
			delete this->array;
			this->array = NULL;
			this->array = new T[a2.size()];
			this->arr_size = a2.size();
			for (unsigned int i = 0; i < (a2.size()); i++)
				this->array[i] = a2.array[i];
			return (*this);
		};

		//배열 연산자 오버로딩.
		T& operator [] ( unsigned int n )
		{
			if (n >= this->arr_size)
				throw Array::OutOfRange();
			return (this->array[n]);
		};

		//배열 연산자 오버로딩. (const 클래스 선언시 필요)
		const T& operator [] ( unsigned int n ) const
		{
			if (n >= this->arr_size)
				throw Array::OutOfRange();
			return (this->array[n]);
		};

		//배열요소의 수를 반환하는 메소드.
		unsigned int size() const { return (this->arr_size); };

		//exception what 오버라이딩 클래스.
		class OutOfRange: public std::exception
		{
			virtual const char * what() const throw()
			{
				return ("out of range");
			}
		};
};

#endif
