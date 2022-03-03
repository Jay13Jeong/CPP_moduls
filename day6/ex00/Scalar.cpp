#include "Scalar.hpp"

//디폴트 생성자 메소드.
Scalar::Scalar(){
	this->c = 0;
	this->isC = false;
	this->i = 0;
	this->isI = false;
	this->f = 0;
	this->isF = false;
	this->d = 0;
	this->isD = false;
}

//매개변수를 받는 생성자 메소드.
Scalar::Scalar(  std::string token  )
{
    this->point_len = get_point_len(const_cast<char*>(token.c_str()));
    //소수점 자리가 없으면 + 1을 해준다.
    this->point_len += (this->point_len == 0);

    //char가 1자리일 때.
    if (token.length() == 1)
    {

        //만약 숫자가 아닌 문자면 int에 아스키넘버를 넣는다.
        if (!isdigit(token.c_str()[0]))
        {
            this->c = token.c_str()[0];
            this->isC = true;
            this->i = this->c;
            this->isI = true;
            this->f = this->c;
            this->isF = true;
            this->d = this->c;
            this->isD = true;
            return ;
        }
        //그 외에 숫자 아스키면. 
        this->i = atoi(const_cast<char*>(token.c_str()));
        this->isI = true;
        this->f = atof(const_cast<char*>(token.c_str()));
        this->isF = true;
        this->d = atof(const_cast<char*>(token.c_str()));
        this->isD = true;
        this->c = i;
        this->isC = true; 
        return ;
    }

    //2자리 이상일 때
    this->i = atoi(const_cast<char*>(token.c_str()));
    this->isI = true;
    this->f = atof(const_cast<char*>(token.c_str()));
    this->isF = true;
    this->d = atof(const_cast<char*>(token.c_str()));
    this->isD = true;
    this->c = this->i;
    this->isC = true;
}

//소멸자
Scalar::~Scalar(){}

void	Scalar::printInfMinus() const{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: -inff" << std::endl;
    std::cout << "double: -inf" << std::endl; 
}

void	Scalar::printInfPlus() const{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: +inff" << std::endl;
    std::cout << "double: +inf" << std::endl; 
}

void	Scalar::printNan() const {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: nanf" << std::endl;
    std::cout << "double: nan" << std::endl;    
}

//변환된 값을 출력하는 메소드.
void	Scalar::printScalar() const {
    std::cout << "char: ";
    if (this->isC)
    {
        //출력가능한 아스키코드만 출력한다.
        if (isprint(this->c))
            std::cout << '\'' << this->c << '\'' << std::endl;
        else
            std::cout << "Non displayable" << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;

    std::cout << "int: ";
    if (this->isI)
        std::cout << this->i << std::endl;
    else
        std::cout << "impossible" << std::endl;

    std::cout << "float: ";
    if (this->isF)
    {
        std::cout.setf(std::ios::fixed);
        std::cout.precision(this->point_len <= 16 ? this->point_len : 16);
        std::cout << this->f << 'f' << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;

    std::cout << "double: ";
    if (this->isD)
    {
        std::cout.setf(std::ios::fixed);
        std::cout.precision(this->point_len);
        std::cout << this->d << std::endl;
    }
    else
        std::cout << "impossible" << std::endl;
}

//소수점 뒤의 숫자갯수를 세는 메소드.
int		Scalar::get_point_len( char *str ){
    int     len = 0;

	if (str[0] == '-')
		str++;
	while (isdigit(*str))
		str++;
	if (*str == '.' && *(str + 1) != '\0')
	{
		while (isdigit(*(++str)))
			len += 1;
	}
    return (len);
}
