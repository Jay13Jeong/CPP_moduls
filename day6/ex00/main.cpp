#include "Scalar.hpp"

//소수에 이상한 문자열이 있는지 검사하는 함수.
bool  check_float(char *str)
{
    double	temp;
	double	minus;
	int		depth;

	minus = 1;
	if (str[0] == '-')
	{
		minus = -1;
		str++;
	}
    temp = atoi(str);
	while (isdigit(*str))
		str++;
	if (*str == '.' && *str != '\0')
	{
		depth = 1;
		while (isdigit(*(++str)))
			temp += (double)(*str - '0') / pow(10, depth++);
		if (*str != '\0')
			return (false);
		else
			return (true);
	}
	if (*str != '\0')
		return (false);
    return (true);
}

int main(int ac, char **av)
{
	//인자는 하나만 받는다.
	if (ac != 2 || (strlen(av[1]) == 0))
	{
		Scalar().printScalar();
		return (1);
	}

	//inf관련 문자인지 검사.
	std::string	symbol[] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};
	int i = std::find(symbol, symbol + 6, av[1]) - symbol;
	if (i < 6)
	{
		if (i == 0 || i == 3)
			Scalar().printInfMinus();
		else if (i == 1 || i == 4)
			Scalar().printInfPlus();
		else
			Scalar().printNan();
		return (0);
	}

	std::string token(av[1]);
	//단일문자일 때.
	if (token.length() == 1)
	{
		Scalar(token).printScalar();
		return (0);
	}
	//문자열 가장 뒤의 f제거
	if (token[token.length() - 1] == 'f')
		token = token.substr(0, token.length() - 1);
	//이상한 문자열 형식인지 검사.
	if (!check_float(const_cast<char*>(token.c_str())) ||
		token[token.length() - 1] == '.')
	{
		Scalar().printScalar();
		return (1);
	}
	//정상이면 실행.
	Scalar(token).printScalar();
}
