#include "./tests.hpp"
#include "../include/Vector.hpp"
#include <iostream>
#include <vector>

int main(void)
{
	// test_vector();
	// test_list();
	// test_map();
	// test_stack();
	// test_queue();

	ft::Vector<int> a((size_t)10, 3);
	ft::Vector<int> b = a;
	std::cout << (a.capacity() == b.capacity()) << std::endl;

	return (0);
}