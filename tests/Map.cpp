#include "tests.hpp"

void test_map(void)
{
	ft::Map<std::string, int> map;
	std::cout << map.max_size() << std::endl;
	(void)map;
}