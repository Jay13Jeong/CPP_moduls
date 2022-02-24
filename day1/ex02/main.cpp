#include <iostream>

int main()
{
	std::string normal_str = "HI THIS IS BRAIN";
	std::string *stringPTR = &normal_str; //문자열의 주소를 담은 stringPTR 포인터변수
	std::string &stringREF = normal_str; //문자열의 참조를 담은 stringREF 레퍼런스변수
	//레퍼런스변수는 선언과 동시에 반드시 참조할 변수를 함께 초기화해야함
	/*그다음 문자열 주소를 각 변수들의 방식으로 출력 */
	std::cout << "normal_str addr\t\t: " << &normal_str << std::endl;
	std::cout << "stringPTR addr\t\t: " << stringPTR << std::endl;
	std::cout << "stringERF addr\t\t: " << &stringREF << std::endl;
	/*마지막으로 포인터변수와 레퍼런스변수로 문자열 출력*/
	std::cout << "pointer string\t\t: " << *stringPTR << std::endl;
	std::cout << "reference string\t: " << stringREF<< std::endl;
}
