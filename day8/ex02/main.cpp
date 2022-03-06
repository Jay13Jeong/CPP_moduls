#include "mutantstack.hpp"

int main()
{
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	
	std::cout << mstack.top() << std::endl;
	
	mstack.pop();
	
	std::cout << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	//////////////////////////////////////////////

	std::cout << "============================" << std::endl;

	MutantStack<int> ms;

	for (int i = 0; i < 5; i++)
		ms.push(i);

	//순방향 출력
	MutantStack<int>::iterator iter = ms.begin();	
	while (iter != ms.end())
		std::cout << *iter++ << std::endl;
	std::cout << std::endl;


	//역방향 출력
	MutantStack<int>::iterator iter2 = ms.end();	
	while ((iter2--) != ms.begin())
		std::cout << *iter2 << std::endl;
	std::cout << std::endl;

	return 0;
}
