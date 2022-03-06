#include "span.hpp"

//디폴트 생성자.
Span::Span(){}

//매개변수를 받는 생성자.
Span::Span( unsigned int N ): N(N){}

//복사생성자
Span::Span( const Span &s2 ) { *this = s2; }

//소멸자
Span::~Span() {}

//대입연산자 오버로딩.
Span & Span::operator = ( const Span &s2 )
{
	if (this == &s2)
		return (*this);
	this->N = s2.N;
	this->vec.clear();
	for (unsigned int i = 0; i < s2.vec.size(); i++)
		this->vec.push_back(s2.vec[i]);
	return (*this);
}

//what 오버로딩. 차이를 계산 할 비교대상이 없을 때.
const char* Span::CanNotCompare::what() const throw()
{
	return ("Can Not Compare");
}

//what 오버로딩. 용량이 초과되었을 때.
const char* Span::CanNotAdd::what() const throw()
{
	return ("Can Not Add");
}

//매개변수를 vector멤버변수에 넣는 함수.
void	Span::addNumber( int num )
{
	//vector의 사이즈가 제한범위 N에 이미 도달하면 예외처리.
	if (this->N == this->vec.size())
		throw Span::CanNotAdd();
	else
		this->vec.push_back(num);
}

//가장 큰 값에서 가장 작은 값의 차 반환 메소드.
int		Span::longestSpan()
{
	//요소가 1개 이하면 예외처리.
	if (this->vec.size() <= 1)
		throw Span::CanNotCompare();
	return (*std::max_element(this->vec.begin(), this->vec.end())
		- *std::min_element(this->vec.begin(), this->vec.end()));
}

//각각 다른 두 요소의 가장 작은 차 반환 메소드.
int		Span::shortestSpan()
{
	//요소가 1개 이하면 예외처리.
	if (this->vec.size() <= 1)
		throw CanNotCompare();
	std::vector<int> temp;
	for (unsigned int i = 0; i < (this->vec.size()); i++)
		temp.push_back(this->vec[i]);
	//오름차순 정렬 후 앞의 두 값의 차를 반환.
	std::sort(temp.begin(), temp.end());
	return (temp[1] - temp[0]);
}
