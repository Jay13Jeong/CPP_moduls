#include "iter.hpp"

int main( void )
{
	//문자열 배열 iter.
	std::string lst[4] = { "jim", "bob", "apple", "banana"};
	iter(lst, 4, print);
	std::cout << std::endl;
	
	//출력 사이즈 1로 조정.
	iter(lst, 1, print);
	std::cout << std::endl;

	//정수 배열 iter.
	int arr[4] = {4, 42, 4242, 0};
	iter(arr, 4, print);

	return (0);
}
