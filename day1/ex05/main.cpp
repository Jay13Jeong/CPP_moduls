#include "Karen.hpp"

int main(void)
{
	Karen karen;

	std::cout << "== debug =======" << std::endl;
	karen.complain("debug");
	std::cout << "== info ========" << std::endl;
	karen.complain("info");
	std::cout << "== warning =====" << std::endl;
	karen.complain("warning");
	std::cout << "== error =======" << std::endl;
	karen.complain("error");
}
