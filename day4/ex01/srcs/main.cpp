#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;	//should not create a leak
	delete i;

	std::cout << "=== Array of Animal ======" << std::endl;
	
	Animal* animals[4];

	//2번까지 개, 4번까지는 고양이로 채우기.
	for (int n = 0; n < 2; n++)
	{
		animals[n] 		= new Dog();
		animals[3 - n]	= new Cat();
		std::cout << std::endl;
	}

	std::cout << "=== Delete Array =========" << std::endl;

	//동적 할당 된 객체를 모두 해제한다.
	for (int n = 0; n < 4; n++)
		delete animals[n];
}
