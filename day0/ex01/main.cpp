#include "phonebook.hpp"

//index를 묻고, 해당 index의 상세정보를 보여주는 함수.
void select_detail(const PhoneBook slot[8])
{
    std::string str_num;
    std::stringstream ss;
    int target_num;

    std::cout << "Please choose an index : ";
    if (!(std::getline(std::cin, str_num)))
        exit(0);
    ss << str_num; //입력을 int형으로 변환을 위해 먼저 stringstream에 값을 대입한다.
    if (ss.fail()) //ss에 failbit이나 badbit이 있는지 확인
    {   //있으면 에러처리
        std::cout << "** invalid index **" << std::endl;
        return ;
    }
    ss >> target_num; //stringstream을 이용해 문자열에서 int형으로 변환
    if (target_num >= 0 && target_num <= 8)
        slot[target_num].prompt_info();
    else
        std::cout << "** invalid index **" << std::endl;
}

//등록된 정보를 index번호 오름차순으로 보여주고, 입력받은 index의 상세정보를 보여주는 함수.
void search_info(const PhoneBook slot[8])
{
    std::cout << "|" << std::setw(6) << std::right << "Index|";
    std::cout << std::setw(11) << std::right << "First Name|";
    std::cout << std::setw(11) << std::right << "Last Name|";
    std::cout << std::setw(11) << std::right << "Nick Name|";
    std::cout << std::setw(11) << std::right << "Cell Phone|";
    std::cout << std::setw(11) << std::right << "DarkSecret|" << std::endl;
    for(int i=0; i<8; i++)
        slot[i].show_info(i); //8개까지 i번째 정보를 요약해서 보여준다.
    select_detail(slot); //index를 묻고, 상세정보를 보여준다.
}

int main(void)
{
    std::string line; //입력을 담을 변수
    PhoneBook slot[8]; //8개의 전화번호부 칸
    int i = -1;
    
    while(1)
    {
        std::cout << "Please enter the command [EXIT, ADD, SEARCH]:\n> ";
        if(!(std::getline(std::cin, line))) //받아온 입력이 null일 떄 종료
            exit(0);
        if (line.compare("EXIT") == 0) //받아온 입력이 EXIT일 때 
        {
            std::cout << "exit" << std::endl;
            exit(0);
        }
        else if (line.compare("ADD") == 0) //입력이 ADD일 때
        {
            ++i %= 8;
            slot[i].add_info(); //전화번호부 정보를 오래된순으로 갱신한다.
        }
        else if (line.compare("SEARCH") == 0) //입력이 search일 때
            search_info(slot); //등록된 정보를 보여주고 찾아본다.
    }
}
