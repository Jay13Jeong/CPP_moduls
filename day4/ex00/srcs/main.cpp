#include "../includes/Cat.hpp"
#include "../includes/Dog.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const WrongAnimal* Wrongmeta = new WrongCat();

	std::cout << Wrongmeta->getType() << " " << std::endl;
	/* 동적바인딩 : 컴파일러는 동적 할당 객체의 포인터만 읽고 실행하다가, */
	/* 가상함수를 만나면 오버라이딩된 함수를 우선으로 덮어 실행한다. */

	/* 만약, makeSound가 가상함수 설정이 되어있지 않을 때 */
	/* WrongCat의 출력이 아닌 WrongAnimal의 함수가 출력된다. */
	Wrongmeta->makeSound();

	delete j;
	delete i;
	delete meta;
	delete Wrongmeta;
}
