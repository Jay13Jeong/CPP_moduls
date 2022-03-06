#include "span.hpp"

int main()
{
	Span sp = Span(5);

	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	///////////////////////////////////////////
	std::cout << "=================" << std::endl;
	
	//크기가 1인 배열에 2개의 요소를 넣을 때.
	try
	{
		Span sp = Span(1);
		sp.addNumber(5);
		sp.addNumber(3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	//비교할 요소가 없을 때.
	try
	{
		Span sp = Span(5);
		sp.addNumber(5);
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	//요소 10000개로 메소드 테스트
	try
	{
		Span sp = Span(10000);
		std::list<int> lst;

		for (int i = 1; i <= 10000; i++)
			lst.push_front(i);

		sp.addNumber(lst.begin(), lst.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
