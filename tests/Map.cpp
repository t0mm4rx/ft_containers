#include "tests.hpp"
#include <map>
#include <utility>

template <class T>
void print_map(T map)
{
	typename T::iterator it = map.begin();
	std::cout << " --- Map of size " << map.size() << " ---" << std::endl;
	while (it != map.end())
	{
		std::cout << it->first << ": " << it->second << std::endl;
		it++;
	}
	std::cout << " --- " << std::endl;
}

void test_map(void)
{
	ft::Map<std::string, int> map;
	map.insert(std::make_pair("test", 42));
	map.insert(std::make_pair("a", 0));
	map.insert(std::make_pair("b", 4));
	map.insert(std::make_pair("b", -2));
	std::cout << map.find("test")->second << std::endl;
	std::cout << map.find("a")->second << std::endl;
	std::cout << map.find("b")->second << std::endl;
	std::cout << map["test"] << std::endl;
	map["c"] = -5;
	std::cout << "c: " << map["c"] << std::endl;

	std::cout << "Iterator" << std::endl;
	print_map(map);

	std::cout << map.count("v") << " 'v' found" << std::endl;
	std::cout << map.count("b") << " 'b' found" << std::endl;

	map.clear();
	print_map(map);

	map["a"] = 1;
	map["b"] = 2;
	map["c"] = 3;

	ft::Map<std::string, int> map2;
	map2["x"] = 42;
	map2["y"] = 43;
	map2["z"] = 44;

	map.swap(map2);
	print_map(map);
	print_map(map2);

	ft::Map<std::string, int>::iterator it = map.end();
	--it;
	std::cout << it->first << std::endl;

	// std::map<std::string, int> t;
	// t["test"] = 4;
	// std::map<std::string, int>::iterator i = t.end();
	// --i;
	// std::cout << i->first << std::endl;
}