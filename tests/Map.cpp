#include "tests.hpp"
#include <map>
#include <utility>

template <class T>
inline void print_map(T map)
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

inline void constructors(void)
{
	print_header("Constructors / Copy");
	std::pair<int, int> a[] = {std::make_pair(0, 1), std::make_pair(1, 0), std::make_pair(2, 1)};
	ft::Map<int, int> m1;
	std::map<int, int> m2;
	check("(default) m1 == m2", (m1 == m2));
	ft::Map<int, int> m3(a, a + 3);
	std::map<int, int> m4(a, a + 3);
	check("(range) m3 == m4", (m3 == m4));
	ft::Map<int, int> m5(m3);
	std::map<int, int> m6(m4);
	check("(copy) m5 == m6", (m3 == m4));
	ft::Map<int, int> m7;
	std::map<int, int> m8;
	m7[0] = 1;
	m7[1] = 2;
	m7[2] = 3;
	m8[0] = 1;
	m8[1] = 2;
	m8[2] = 3;
	ft::Map<int, int> m9;
	std::map<int, int> m10;
	m9 = m7;
	m10 = m8;
	check("(copy) m9 == m10", (m9 == m10));
}

inline void max_size(void)
{
	print_header("Size");
	ft::Map<int, int> m1;
	std::map<int, int> m2;
	check("m1.max_size() == m2.max_size()", m1.max_size(), m2.max_size());
	ft::Map<std::string, int> m3;
	std::map<std::string, int> m4;
	check("m3.max_size() == m4.max_size()", m3.max_size(), m4.max_size());
}

inline void access_operator(void)
{
	print_header("[] operator");
	ft::Map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 0;
	m1["c"] = 42;
	m1["d"] = -5;
	m2["d"] = 11;
	m1["test"] = 100;
	m2["a"] = 1;
	m2["b"] = 0;
	m2["c"] = 42;
	m2["d"] = -5;
	m2["d"] = 11;
	m2["test"] = 100;
	check("m1 == m2", m1 == m2);
	check("m1['a'] == m2['a']", m1["a"], m2["a"]);
	check("m1['test'] == m2['test']", m1["test"], m2["test"]);
	check("m1['z'] == m2['z']", m1["z"], m2["z"]);
}

inline void insert(void)
{
	print_header("Insert");
	std::pair<int, int> a[] = {std::make_pair(0, 1), std::make_pair(1, 0), std::make_pair(2, 1)};
	ft::Map<int, int> m1(a, a + 3);
	std::map<int, int> m2(a, a + 3);
	m1.insert(++m1.begin(), std::make_pair(5, 5));
	m2.insert(++m2.begin(), std::make_pair(5, 5));
	check("m1 == m2", m1 == m2);
	m1.insert(std::make_pair(5, 0));
	m2.insert(std::make_pair(5, 0));
	m1.insert(std::make_pair(10, 54));
	m2.insert(std::make_pair(10, 54));
	check("m1 == m2", m1 == m2);
}

inline void erase(void)
{
	print_header("Erase");
	ft::Map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["test"] = 1;
	m1["a"] = 2;
	m1["b"] = 3;
	m1["c"] = 4;
	m1["d"] = 6;
	m1["e"] = 8;
	m2["test"] = 1;
	m2["a"] = 2;
	m2["b"] = 3;
	m2["c"] = 4;
	m2["d"] = 6;
	m2["e"] = 8;
	check("m1 == m2", m1 == m2);
	m1.erase(++m1.begin());
	m2.erase(++m2.begin());
	check("m1 == m2", m1 == m2);
	m1.erase(++m1.begin(), --m1.end());
	m2.erase(++m2.begin(), --m2.end());
	check("m1 == m2", m1 == m2);
	m1.erase("a");
	m2.erase("a");
	check("m1 == m2", m1 == m2);
}

inline void swap(void)
{
	print_header("Swap");
	ft::Map<std::string, int> m1;
	std::map<std::string, int> m2;
	ft::Map<std::string, int> m3;
	std::map<std::string, int> m4;
	m1["a"] = 1;
	m1["b"] = 2;
	m1["c"] = 3;
	m2["a"] = 1;
	m2["b"] = 2;
	m2["c"] = 3;
	m3["a"] = 42;
	m3["b"] = 21;
	m4["a"] = 42;
	m4["b"] = 21;
	m1.swap(m3);
	m2.swap(m4);
	check("m1 == m2", m1 == m2);
	check("m3 == m4", m3 == m4);
}

inline void clear(void)
{
	print_header("Clear");
	ft::Map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m2["a"] = 1;
	m2["b"] = 42;
	m1.clear();
	m2.clear();
	check("m1 == m2", m1 == m2);
	print_map(m1);
	print_map(m2);
}

inline void find(void)
{
	print_header("Find");
	ft::Map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m2["a"] = 1;
	m2["b"] = 42;
	check("m1.find('a') == m2.find('a')", m1.find("a")->second, m2.find("a")->second);
	check("m1.find('z') == m2.find('z')", m1.find("a")->second, m2.find("a")->second);
}

inline void count(void)
{
	print_header("Count");
	ft::Map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m1["b"] = 21;
	m2["a"] = 1;
	m2["b"] = 42;
	m2["b"] = 21;
	check("m1.count('a') == m2.count('a')", m1.count("a"), m2.count("a"));
	check("m1.count('b') == m2.count('b')", m1.count("b"), m2.count("b"));
	check("m1.count('z') == m2.count('z')", m1.count("z"), m2.count("z"));
}

inline void bounds()
{
	print_header("Bounds");
	ft::Map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m1["c"] = 42;
	m1["d"] = 42;
	m2["a"] = 1;
	m2["b"] = 42;
	m2["c"] = 42;
	m2["d"] = 42;
	check("m1.lower_bound() == m2.lower_bound()", m1.lower_bound("a")->first, m2.lower_bound("a")->first);
	check("m1.lower_bound() == m2.lower_bound()", m1.lower_bound("c")->first, m2.lower_bound("c")->first);
	check("m1.upper_bound() == m2.upper_bound()", m1.upper_bound("a")->first, m2.upper_bound("a")->first);
	check("m1.upper_bound() == m2.upper_bound()", m1.upper_bound("c")->first, m2.upper_bound("c")->first);
}

inline void range(void)
{
	print_header("Equal range");
	ft::Map<std::string, int> m1;
	std::map<std::string, int> m2;
	m1["a"] = 1;
	m1["b"] = 42;
	m1["c"] = 42;
	m1["d"] = 42;
	m2["a"] = 1;
	m2["b"] = 42;
	m2["c"] = 42;
	m2["d"] = 42;
	std::pair<ft::Map<std::string, int>::iterator, ft::Map<std::string, int>::iterator> a = m1.equal_range("a");
	std::pair<std::map<std::string, int>::iterator, std::map<std::string, int>::iterator> b = m2.equal_range("a");
	check("a.first->first == b.first->first", a.first->first, b.first->first);
	check("a.first->second == b.first->second", a.first->second, b.first->second);
	check("a.second->first == b.second->first", a.second->first, b.second->first);
	check("a.second->second == b.second->second", a.second->second, b.second->second);
}

inline void operators(void)
{
	
}

void test_map(void)
{
	print_header("Map");
	constructors();
	max_size();
	access_operator();
	insert();
	erase();
	swap();
	clear();
	find();
	count();
	bounds();
	range();
}