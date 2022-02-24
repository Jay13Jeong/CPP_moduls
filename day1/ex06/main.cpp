#include "Karen.hpp"

int main(int ac, char **av)
{
	Karen karen;

	if (ac == 2)
		karen.filter(av[1]);
	else
		karen.filter("print default msg");
	return (0);
}
