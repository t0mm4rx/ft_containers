#include "tests.hpp"
#include <list>

template <class T>
void print_list(T &list)
{
	typename T::iterator it = list.begin();
	while (it != list.end())
	{
		std::cout << *it;
		if (it + 1 != list.end())
			std::cout << " - ";
		it++;
	}
	std::cout << std::endl;
	// (void)list;
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

	for (int i = -10; i < 11; i++)
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
}