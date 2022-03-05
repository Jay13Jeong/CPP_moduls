#include <iostream>
#include <string>

//테스트용 Data구조체.
struct Data
{
	long long	ll;
	int			i;
	char		c;
	bool		b;
};

//직렬화 함수.
uintptr_t serialize(Data* ptr)
{
	//reinerpret_cast를 통해서 
	//사용자 지정한 임의의 형태로 자료형을 변환 할 수 있다.
	return (reinterpret_cast<uintptr_t>(ptr));
}

//역직렬화 함수.
Data* deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int main()
{
	Data *d1 = new Data();

	d1->ll = 1 << 31;
	d1->i = 1234;
	d1->c = '*';
	d1->b = true;

	std::cout << d1 << std::endl;
	std::cout << d1->ll << std::endl;
	std::cout << d1->i << std::endl;
	std::cout << d1->c << std::endl;
	std::cout << d1->b << std::endl;
	std::cout << std::endl;

	/* 현재 시스템 외에 다른 시스템으로 객체를 보내기위해서 */
	/* 읽을 시스템이 이해 할 수 있는 byte형태로 변환하는 것이 직렬화다.   */
	/* 보통 파일로 만들거나 네트워크 송수신용으로 사용.   */
	
	/* uintptr_t는 시스템의 포인터주소와 같은 크기의 자료형이며   */
	/* 다른 환경으로 이식이 가능한 자료형이다.  */
	uintptr_t r1 = serialize(d1);
	Data *d2 = deserialize(r1);

	std::cout << d2 << std::endl;
	std::cout << d2->ll << std::endl;
	std::cout << d2->i << std::endl;
	std::cout << d2->c << std::endl;
	std::cout << d2->b << std::endl;

	delete d1;

	return (0);
}
