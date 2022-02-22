#include "phonebook.hpp"

//trim
std::string trim(std::string str)
{
    for (int i = 0; i < str.length(); i++) //앞부분 트림
    {
        if (isspace(str[i]))
            continue;
        str.erase(0, i);
        break;
    }
    for (int i = str.length() - 1; i >= 0; i--) //뒷부분 트림
    {
        if (isspace(str[i]))
            continue;
        str.erase(i + 1, str.length());
        break;
    }
    if (isspace(str[0])) //공백만 들어오면 빈문자열 리턴
        return ("");
    return (str);
}

//문자열이 모두 '0'아스키부터 '9'아스키로 이루어져있는지 검사하는 함수.
bool chk_all_num(const std::string str)
{
    for (int i = 0; i < str.length(); i++)
        if (!(isdigit(str[i])))
            return (false);
    return (true);
}

//전화번호부 객체에 정보를 입력받아 할당하는 함수.
void PhoneBook::add_info(void)
{
    while (1)
    {
        std::cout << "First name\t: ";
        if (!(std::getline(std::cin, first_name)))
            exit(0);
        first_name = trim(first_name);
        if (first_name.length() >= 1) //trim된 문자열이 비어있으면 다시 입력받는다.
            break;
        std::cout << "** empty info **" << std::endl;
    }
    while (1)
    {
        std::cout << "Last name\t: ";
        if (!(std::getline(std::cin, last_name)))
            exit(0);
        last_name = trim(last_name);
        if (last_name.length() >= 1)
            break;
        std::cout << "** empty info **" << std::endl;
    }
    while (1)
    {
        std::cout << "Nick name\t:";
        if (!(std::getline(std::cin, nick_name)))
            exit(0);
        nick_name = trim(nick_name);
        if (nick_name.length() >= 1)
            break;
        std::cout << "** empty info **" << std::endl;
    }
    while(1)
    {
        std::cout << "Phone number\t: ";
        if (!(std::getline(std::cin, phone_number)))
            exit(0);
        if (chk_all_num(phone_number) && (phone_number.length() >= 1)) //입력에 숫자이외의 문자가 있다면 다시 입력받는다.
            break;
        std::cout << "** Phone numbers only use numbers. **" << std::endl;
    }
    while (1)
    {
        std::cout << "darkest secret...\t: ";
        if (!(std::getline(std::cin, darkest_secret)))
            exit(0);
        darkest_secret = trim(darkest_secret);
        if (darkest_secret.length() >= 1)
            break;
        std::cout << "** empty info **" << std::endl;
    }
}

//받아온 문자열을 10개씩 "|"문자 기준으로 오른쪽 정렬해서 출력하는 함수.
void assign_text(const std::string text)
{
    if (text.length() <= 10) //문자가 10개이하일 때 오른쪽 정렬로 10칸까지 공백을 채워서 출력
        std::cout << std::setw(10) << std::right << text;
    else //문자가 10개를 초과하면 10번째문자는 .으로 표기하고, 나머지정보는 생략
        std::cout << text.substr(0,9) + ".";
    std::cout << "|";
}

//받아온 i를 index컬럼에 출력시키고 현재객체의 정보를 요약해서 출력하는 함수.
void PhoneBook::show_info(const int i) const
{
    std::cout << "|" << std::setw(5) << std::right << i << "|";
    assign_text(first_name);
    assign_text(last_name);
    assign_text(nick_name);
    assign_text(phone_number);
    assign_text(darkest_secret);
    std::cout << std::endl;
}

//현재 객체의 상세정보를 한줄씩 표시하는 함수.
void PhoneBook::prompt_info(void) const
{
    std::cout << "First name\t: " << first_name << std::endl;
    std::cout << "Last name\t: " << last_name << std::endl;
    std::cout << "Nick name\t: " << nick_name << std::endl;
    std::cout << "Phone number\t: " << phone_number << std::endl;
    std::cout << "Darkest secret\t: " << darkest_secret << std::endl;
}