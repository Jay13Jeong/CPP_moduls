#include <iostream>
#include <fstream>
#include <string>

//참조변수로 문자열을 받고, 문자열 속의 s1을 s2로 치환하는 call by ref 함수.
void	my_replace(std::string& line, std::string s1, std::string s2)
{
	int	target	= 0;
	int	gap		= s1.length() - s2.length();
	int	changed	= 0;
	int	line_len= line.length();

	while (1)
	{
		//s1이 있는지 검사.
		target = line.find(s1);
		//없으면 종료.
		if (target == -1)
			break;
		//있으면 치환.
		line.erase(target, s1.length());
		line.insert(target, s2);
		//문자열의 포인트를 치환된 문자열 뒤로 옮김.
		line += target + s2.length();
		//수정된 문자열의 길이차이를 기록
		changed += gap;
	}
	//치환뒤 쓰레기값을 제거하기위해, 치환된 길이만큼만 출력한다. 
	line = line.substr(0, line_len - changed);
}

int main(int argc, char **argv)
{
	std::ifstream	read_file;
	std::ofstream	write_file;
	std::string		line;

	//인자가 3개가 아니거나 파일이름이 비어있으면 에러
	if (argc != 4 || ((std::string)argv[1]).empty())
	{
		std::cout << "** invalid args **" << std::endl;
		exit(EXIT_FAILURE);
	}
	//바꿀 파일이 연결
	read_file.open(argv[1]);
	if (!(read_file.is_open())) //정상적으로 연결되어있는지 검사
	{
		std::cout << "** invalid file **" << std::endl;
		exit(EXIT_FAILURE);
	}
	//바꿀 문자열이 비어있으면 에러처리
	if (((std::string)argv[2]).empty() || ((std::string)argv[3]).empty())
	{
		std::cout << "** string empty error **" << std::endl;
		read_file.close(); //실패시 read_file닫기
		exit(EXIT_FAILURE);
	}
	//새로만들 파일만들고 연결
	write_file.open((std::string)argv[1] + ".replace");
	if (!(write_file.is_open())) //정상적으로 연결되어있는지 검사
	{
		std::cout << "** create file error **" << std::endl;
		read_file.close();
		exit(EXIT_FAILURE);
	}
	//파일을 한줄씩 읽고, 수정하고, 새파일에 저장
	while (getline(read_file, line))
	{
		my_replace(line, argv[2], argv[3]);
		write_file << line << std::endl;
	}
	read_file.close();
	write_file.close();
	return (0);
}
