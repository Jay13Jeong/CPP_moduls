#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <string>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <deque>
#include <list>

template <typename T>
void	easyfind(T container, int target)
{
	if (std::find(container.begin(), container.end(), target) != container.end())
		std::cout << target << std::endl;
	else
		throw std::runtime_error("Not Find Exception");
}

#endif
