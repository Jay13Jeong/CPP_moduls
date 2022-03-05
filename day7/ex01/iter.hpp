#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void	iter(T *array, unsigned int size, void (*f)(const T&))
{
	for (unsigned int i = 0; i < size; i++)
		(*f)(array[i]);
}

template <typename T>
void print(const T &var)
{
	std::cout << var << std::endl;
}

#endif
