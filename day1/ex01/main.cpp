#include "Zombie.hpp"

//문자열이 모두 '0'아스키부터 '9'아스키로 이루어져있는지 검사하는 함수.
bool chk_all_num(const std::string str)
{
    for (int i = 0; i < str.length(); i++)
        if (!(isdigit(str[i])))
            return (false);
    return (true);
}

int main(void)
{
	Zombie				*zombies;
	int					n;
	std::string			temp;
	std::stringstream	ss;

	std::cout << "How many zombies are you going to make?";
	std::cout << std::endl;
	if (!(std::getline(std::cin, temp)))
		exit(0);
	if (!(chk_all_num(temp)) || temp.length() < 1)
	{	//입력이 숫자가 아니거나 빈문자열이면 에러
		std::cout << "** invalid number **" << std::endl;
		exit(0);
	}
	ss << temp;
    if (ss.fail()) //ss에 failbit이나 badbit이 있는지 확인
    {   //있으면 에러처리
        std::cout << "** Conversion error. **" << std::endl;
        exit(0);
    }
	ss >> n;
	if (n < 1) //생성할 좀비가 없으면 아무것도 안한다.
		exit(0);
	zombies = zombieHorde(n, "zombie");
	delete[] zombies; //[]를 안하면 첫번째만 소멸됨.
	return (0);
}