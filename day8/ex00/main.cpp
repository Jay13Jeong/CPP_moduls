#include "easyfind.hpp"

int main()
{
	//deque
	try
	{
		std::deque<int> dq;

		dq.push_back(1);
		dq.push_back(2);
		dq.push_back(3);
		dq.push_back(4);
		dq.push_back(5);
		easyfind(dq, 3);
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	//list
	try
	{
		std::list<int> lst;
			
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3);
		lst.push_back(4);
		lst.push_back(5);
		easyfind(lst, 5);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	//exception
	try
	{
		std::list<int> lst;
		
		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3);
		lst.push_back(4);
		lst.push_back(5);
		easyfind(lst, 9);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
