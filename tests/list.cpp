#include "tests.hpp"
#include <list>
#include <stdlib.h>

template <class T>
void print_list(T &list)
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

void test_list(void)
{
	std::srand(time(0));
	// Default constructor
	ft::List<int> list;

	std::cout << "Max size: " << list.max_size() << std::endl;
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);
	// print_list(list);
	std::cout << list.front() << std::endl;
	std::cout << list.back() << std::endl;
	std::cout << "Pop front" << std::endl;
	list.pop_front();
	std::cout << list.front() << std::endl;
	std::cout << list.back() << std::endl;
	std::cout << "Pop back" << std::endl;
	list.pop_back();
	std::cout << list.front() << std::endl;
	std::cout << list.back() << std::endl;
	std::cout << "Push front" << std::endl;
	list.push_front(42);
	std::cout << list.front() << std::endl;
	std::cout << list.back() << std::endl;
	std::cout << "Clear" << std::endl;
	list.clear();
	std::cout << list.front() << std::endl;
	std::cout << list.back() << std::endl;

	for (int i = -5; i < 6; i++)
		list.push_back(i * 2);

	// Iterator
	ft::List<int>::iterator it = list.begin();
	std::cout << *it << std::endl;
	it++;
	std::cout << *it << std::endl;
	it--;
	std::cout << *it << std::endl;
	it += 11;
	std::cout << *it << std::endl;

	// Forward iterator
	print_list(list);

	// Fill constructor
	ft::List<int> list2((size_t)10, 42);
	std::cout << "Size: " << list2.size() << std::endl;
	print_list(list2);

	// Copy constructor
	ft::List<int> list3(list2);
	print_list(list3);

	// Swap
	std::cout << "First swap" << std::endl;
	list3.swap(list);
	print_list(list3);
	print_list(list);
	std::cout << "Second swap" << std::endl;
	ft::swap(list, list3);
	print_list(list3);
	print_list(list);

	// Reverse
	std::cout << "Reverse" << std::endl;
	list.reverse();
	print_list(list);

	// Simple sort
	std::cout << "Sort" << std::endl;
	ft::List<int> list4;
	for (int i = 0; i < 20; i++)
		list4.push_back(std::rand() % 100);
	print_list(list4);
	list4.sort();
	print_list(list4);

	// Compare sort
	std::cout << "Custom sort" << std::endl;
	list4.clear();
	for (int i = 0; i < 20; i++)
		list4.push_back(std::rand() % 100);
	print_list(list4);
	list4.sort(Greater());
	print_list(list4);

	// Single element insert
	std::cout << "Insert single element" << std::endl;
	print_list(list);
	list.insert(list.begin() + 2, 42);
	print_list(list);
	list.insert(list.begin(), 42);
	list.insert(list.end(), 42);
	print_list(list);
	
	// Fill insert
	std::cout << "Fill insert" << std::endl;
	list.insert(list.end() - 4, (size_t)5, 0);
	print_list(list);

	// Range insert
	std::cout << "Range insert" << std::endl;
	list.insert(list.begin() + 1, list4.begin(), list4.begin() + 3);
	print_list(list);

	ft::List<int> x((size_t)3, 0);
	ft::List<int> y;
	y.push_back(1);
	y.push_back(2);
	y.push_back(3);
	print_list(x);
	x.insert(x.begin(), y.begin(), y.end());
	print_list(x);

	// Merge
	std::cout << "Merge" << std::endl;
	ft::List<int> a;
	ft::List<int> b;
	a.push_back(1);
	a.push_back(3);
	a.push_back(6);
	b.push_back(2);
	b.push_back(4);
	b.push_back(5);
	a.merge(b);
	print_list(a);
	print_list(b);

	// Erase single element
	std::cout << "Delete begin() + 2" << std::endl;
	a.erase(a.begin() + 2);
	print_list(a);
	std::cout << "Delete end() - 2" << std::endl;
	a.erase(a.end() - 2);
	print_list(a);

	// Erase range
	std::cout << "Delete range" << std::endl;
	a.push_back(7);
	a.push_back(8);
	a.push_back(9);
	print_list(a);
	a.erase(a.begin() + 1, a.begin() + 4);
	print_list(a);

	// Resize
	std::cout << "Resize" << std::endl;
	a.resize(2, 0);
	print_list(a);
	a.resize(10, 0);
	print_list(a);

	// Remove
	std::cout << "Remove" << std::endl;
	a.push_back(1);
	a.insert(a.begin() + 4, 1);
	print_list(a);
	a.remove(1);
	print_list(a);

	// Unique
	std::cout << "Sort" << std::endl;
	ft::List<int> v((size_t)3, 0);
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(0);
	v.push_back(1);
	print_list(v);
	v.unique();
	print_list(v);

	// Reverse operator
	std::cout << "Reverse operator" << std::endl;
	ft::List<int>::reverse_iterator rit = v.rbegin();
	while (rit != v.rend())
	{
		std::cout << *rit;
		if (rit + 1 != v.rend())
			std::cout << " - ";
		rit++;
	}
	std::cout << std::endl;

	// Splice
	std::cout << "Splice" << std::endl;
	ft::List<int> p((size_t)5, 0);
	ft::List<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.splice(l.end(), p, p.begin(), p.end());
	
	print_list(l);
	print_list(p);

	p.push_front(1);
	p.push_front(2);
	p.push_front(3);
	print_list(l);
	print_list(p);
	l.splice(l.begin() + 1, p, p.begin() + 1);
	print_list(l);
	print_list(p);

	// Operator
	std::cout << "Operators" << std::endl;
	list2 = a;
	print_list(list2);
	print_list(a);
	std::cout << "list2 == a: " << (list2 == a) << std::endl;
	std::cout << "list2 > a: " << (list2 > a) << std::endl;
	std::cout << "list2 < a: " << (list2 < a) << std::endl;
	std::cout << "list2 <= a: " << (list2 <= a) << std::endl;
	std::cout << "list2 >= a: " << (list2 >= a) << std::endl;
	a.push_back(42);
	print_list(list2);
	print_list(a);
	std::cout << "list2 == a: " << (list2 == a) << std::endl;
	std::cout << "list2 > a: " << (list2 > a) << std::endl;
	std::cout << "list2 < a: " << (list2 < a) << std::endl;
	std::cout << "list2 <= a: " << (list2 <= a) << std::endl;
	std::cout << "list2 >= a: " << (list2 >= a) << std::endl;
}