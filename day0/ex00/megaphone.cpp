#include <iostream>
#include <cctype>

int main(int argc, char **argv) 
{
	if(argc >= 2) //들어온 인자가 1개 이상일 때 받은 문자열을 전부 대문자로 재출력함.
    {
        for(int i = 1; i < argc; i++)
            for(int j = 0; argv[i][j] != 0; j++)
                std::cout << (char) toupper(argv[i][j]);
        std::cout << std::endl;
        return (0);
	} //들어온 인자가 없으면 아래문구를 출력한다.
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	return (0);
}
