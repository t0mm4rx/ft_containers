#include "tests.hpp"
#include <list>
#include <stdlib.h>

template <class T>
static void print_list(T &list)
{
	typename T::iterator it = list.begin();
	typename T::iterator it2;
	std::cout << "Size " << list.size() << " : ";
	while (it != list.end())
	{
		std::cout << *it;
		it2 = it;
		it2++;
		if (it2 != list.end())
			std::cout << " - ";
		it++;
	}
	std::cout << std::endl;
}

struct Greater {
    bool operator()(const int &a, const int &b) {return a < b;}
};

static void constructors(void)
{
	print_header("Default constructor");
	int test[] = {0, 1, 2, 3};
	ft::List<int> l1;
	std::list<int> l2;
	check("(default) l1 == l2", l1 == l2);
	ft::List<int> l3((size_t)10);
	std::list<int> l4((size_t)10);
	check("(fill with default value) l3 == l4", l3 == l4);
	ft::List<int> l5((size_t)10, 42);
	std::list<int> l6((size_t)10, 42);
	check("(fill) l5 == l6", l5 == l6);
	ft::List<int> l7(test, test + 4);
	std::list<int> l8(test, test + 4);
	check("(iterator) l7 == l8", l7 == l8);
	ft::List<int> l9(l7);
	std::list<int> l10(l8);
	check("(copy) l9 == l10", l9 == l10);
}

static void copy_operator(void)
{
	print_header("Operator =");
	int test[] = {0, 1, 2, 3};
	ft::List<int> l1(test, test + 4);
	std::list<int> l2(test, test + 4);
	ft::List<int> l3;
	std::list<int> l4;
	l3 = l1;
	l4 = l2;
	check("l1 == l3", l1 == l3);
	check("l2 == l4", l2 == l4);
	l1.push_back(1);
	l2.push_back(1);
	check("l1 != l3", l1 != l3);
	check("l2 != l4", l2 != l4);
}

static void max_size(void)
{
	print_header("Max size");
	ft::List<int> l1;
	std::list<int> l2;
	ft::List<std::string> l3;
	std::list<std::string> l4;
	check("l1.max_size() == l2.max_size()", l1.max_size(), l2.max_size());
	check("l3.max_size() == l4.max_size()", l3.max_size(), l4.max_size());
}

static void front_back(void)
{
	print_header("Front / Back");
	ft::List<int> l1;
	std::list<int> l2;
	check("front == back", l1.front() == l1.back());
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l2.push_back(1);
	l2.push_back(2);
	l2.push_back(3);
	check("l1.front() == l2.front()", l1.front(), l2.front());
	check("l1.back() == l2.back()", l1.back(), l2.back());
}

static void assign(void)
{
	print_header("Assign");
	int test[] = {0, 1, 2, 3};
	ft::List<int> l1;
	std::list<int> l2;
	l1.assign(test, test + 4);
	l2.assign(test, test + 4);
	check("l1 == l2", l1 == l2);
	l1.assign((size_t)10, 42);
	l2.assign((size_t)10, 42);
	check("l1 == l2", l1 == l2);
}

static void push(void)
{
	print_header("Push front/back");
	ft::List<int> l1;
	std::list<int> l2;
	for (int _ = 0; _ < 100; _++)
	{
		if (rand() % 2)
		{
			int n = rand() % 100;
			l1.push_front(n);
			l2.push_front(n);
		}
		else
		{
			int n = rand() % 100;
			l1.push_back(n);
			l2.push_back(n);
		}
	}
	check("l1 == l2", l1 == l2);
}

static void swap(void)
{
	print_header("Swap");
	ft::List<int> l1;
	std::list<int> l2;
	ft::List<int> l3;
	std::list<int> l4;
	l1.push_front(1);
	l1.push_front(2);
	l1.push_front(3);
	l2.push_front(1);
	l2.push_front(2);
	l2.push_front(3);
	l3.push_front(42);
	l4.push_front(42);
	l1.swap(l3);
	l2.swap(l4);
	check("l1 == l2", l1 == l2);
	check("l3 == l4", l3 == l4);
}

static void resize(void)
{
	print_header("Resize / Clear");
	ft::List<int> l1;
	std::list<int> l2;
	l1.resize(10, 42);
	l2.resize(10, 42);
	check("l1 == l2", l1 == l2);
	l1.resize(2, 42);
	l2.resize(2, 42);
	check("l1 == l2", l1 == l2);
	l1.resize(0, 0);
	l2.resize(0, 0);
	check("l1 == l2", l1 == l2);
	l1.resize(2, 42);
	l1.clear();
	l2.resize(2, 42);
	l2.clear();
	check("l1 == l2", l1 == l2);
}

static void splice(void)
{
	print_header("Splice");
	ft::List<int> l1((size_t)10, 5);
	std::list<int> l2((size_t)10, 5);
	ft::List<int> l3((size_t)3, 0);
	std::list<int> l4((size_t)3, 0);
	l1.splice(++l1.begin(), l3);
	l2.splice(++l2.begin(), l4);
	check("l1 == l2", l1 == l2);
	check("l3 == l4", l3 == l4);
	l1.assign((size_t)10, 5);
	l2.assign((size_t)10, 5);
	l3.assign((size_t)3, 0);
	l4.assign((size_t)3, 0);
	l1.splice(l1.begin(), l3, ++l3.begin());
	l2.splice(l2.begin(), l4, ++l4.begin());
	check("l1 == l2", l1 == l2);
	check("l3 == l4", l3 == l4);
	l1.assign((size_t)10, 5);
	l2.assign((size_t)10, 5);
	l3.assign((size_t)3, 0);
	l4.assign((size_t)3, 0);
	l1.splice(l1.begin(), l3, ++l3.begin(), --l3.end());
	l2.splice(l2.begin(), l4, ++l4.begin(), --l4.end());
	check("l1 == l2", l1 == l2);
	check("l3 == l4", l3 == l4);
}

static bool even(const int& value) { return (value % 2) == 0; } 

static void remove(void)
{
	print_header("Remove / Remove if");
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::List<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	l1.remove(0);
	l1.remove(5);
	l2.remove(0);
	l2.remove(5);
	check("l1 == l2", l1 == l2);
	l1.remove_if(even);
	l2.remove_if(even);
	check("l1 == l2", l1 == l2);
}

static void erase(void)
{
	print_header("Erase");
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::List<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	l1.erase(l1.begin());
	l1.erase(--l1.end());
	l1.erase(--l1.end());
	l2.erase(l2.begin());
	l2.erase(--l2.end());
	l2.erase(--l2.end());
	check("l1 == l2", l1 == l2);
	l1.erase(++l1.begin(), --l1.end());
	l2.erase(++l2.begin(), --l2.end());
	check("l1 == l2", l1 == l2);
}

static bool compare(int a, int b) 
{ 
    return (a >= b); 
} 

static void unique()
{
	print_header("Unique");
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::List<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	l1.unique();
	l2.unique();
	check("l1 == l2", l1 == l2);
	l1.assign(test, test + 14);
	l2.assign(test, test + 14);
	l1.unique(compare);
	l2.unique(compare);
	check("l1 == l2", l1 == l2);
}

static bool compare2(int a, int b) 
{ 
    return (a == b); 
} 

static void merge(void)
{
	print_header("Merge");
	int test[] = {1, 2, 3};
	int test2[] = {42, 43, 44};
	ft::List<int> l1(test, test + 3);
	std::list<int> l2(test, test + 3);
	ft::List<int> l3(test2, test2 + 3);
	std::list<int> l4(test2, test2 + 3);
	l1.merge(l3);
	l2.merge(l4);
	check("l1 == l2", l1 == l2);
	check("l3 == l4", l3 == l4);
	l1.assign(test, test + 3);
	l2.assign(test, test + 3);
	l3.assign(test2, test2 + 3);
	l4.assign(test2, test2 + 3);
	l1.merge(l3, compare2);
	l2.merge(l4, compare2);
	check("l1 == l2", l1 == l2);
	check("l3 == l4", l3 == l4);
}

static void reverse(void)
{
	print_header("Reverse");
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::List<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	l1.reverse();
	l2.reverse();
	check("l1 == l2", l1 == l2);
}

static void operators(void)
{
	print_header("Operators");
	int test[] = {0, 0, 0, 1, 2, 0, 5, 3, 4, 5, 1, -1, 0, 1};
	ft::List<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	ft::List<int> l3(l1);
	std::list<int> l4(l2);
	check("l1 == l2", (l1 == l3), (l2 == l4));
	check("l1 != l2", (l1 != l3), (l2 != l4));
	check("l1 > l2", (l1 > l3), (l2 > l4));
	check("l1 < l2", (l1 < l3), (l2 < l4));
	check("l1 >= l2", (l1 >= l3), (l2 >= l4));
	check("l1 <= l2", (l1 <= l3), (l2 <= l4));
	l1.push_back(42);
	l2.push_back(42);
	check("l1 == l2", (l1 == l3), (l2 == l4));
	check("l1 != l2", (l1 != l3), (l2 != l4));
	check("l1 > l2", (l1 > l3), (l2 > l4));
	check("l1 < l2", (l1 < l3), (l2 < l4));
	check("l1 >= l2", (l1 >= l3), (l2 >= l4));
	check("l1 <= l2", (l1 <= l3), (l2 <= l4));
	l3.push_back(43);
	l4.push_back(43);
	check("l1 == l2", (l1 == l3), (l2 == l4));
	check("l1 != l2", (l1 != l3), (l2 != l4));
	check("l1 > l2", (l1 > l3), (l2 > l4));
	check("l1 < l2", (l1 < l3), (l2 < l4));
	check("l1 >= l2", (l1 >= l3), (l2 >= l4));
	check("l1 <= l2", (l1 <= l3), (l2 <= l4));
}

void test_list(void)
{
	std::srand(time(0));
	print_header("List");
	constructors();
	copy_operator();
	max_size();
	front_back();
	assign();
	push();
	swap();
	resize();
	splice();
	remove();
	erase();
	unique();
	merge();
	reverse();
	operators();
}