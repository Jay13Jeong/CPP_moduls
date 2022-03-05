#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

/* 구조체처럼 큰 자료형을 넣을 수 있기에 매개변수를 참조로 받는다. */
/* 그냥받으면 함수를 실행 할 때마다 값이 복사되어 기능저하. */
template <typename T>
void	swap(T &t1, T &t2)
{
	T temp;
	temp = t1;
	t1 = t2;
	t2 = temp;
}

template <typename T>
T	min(T &t1, T &t2)
{
	return ((t1 < t2) ? t1 : t2);
}

template <typename T>
T	max(T &t1, T &t2)
{
	return ((t1 > t2) ? t1 : t2);
}
#endif
