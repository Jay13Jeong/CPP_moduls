#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class PhoneBook //전화번호부 클래스
{   //cpp의 클래스에 선언된 변수,함수는 기본 private처리됨(struct와 반대) 
    std::string first_name; //이름
    std::string last_name; //성
    std::string nick_name; //별명
    std::string phone_number; //전화번호
    std::string darkest_secret; //어두운 비밀

    public: //public선언하면 이 클래스로 만들어진 객체는 아래의 변수,함수에 접근 가능
        void add_info(void);
        void prompt_info(void) const; /* 함수 마지막에 const를 선언하면 */
        void show_info(const int i) const; /* 클래스의 private 영역을 수정 할 수 없음 */
    //인자앞에 const를 붙이면 함수내부에서 받아온 인자를 수정 할 수 없음      
};

#endif
