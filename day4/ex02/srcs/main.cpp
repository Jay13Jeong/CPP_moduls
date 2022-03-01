#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"

int main()
{
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	/* Animal 객체를 생성하려고하면 순수가상함수 때문에 생성 불가 */
	// const Animal* a = new Animal();
	
	std::cout << std::endl;

	dog->makeSound();
	cat->makeSound();

	std::cout << std::endl;

	delete dog;
	delete cat;
}
