#include "../include/Vector.hpp"
#include "./tests.hpp"
#include <iostream>
#include <vector>

int main(void)
{
	/*
	// Default constructor
	ft::Vector<int> vec;
	// push_back
	vec.push_back(4);
	vec.push_back(8);
	vec.push_back(42);
	vec.push_back(21);
	vec.push_back(-42);
	print_vector(vec);

	// Simple iterator
	ft::Vector<int>::iterator it = vec.begin();
	it += 2;
	// Insert single element
	vec.insert(it, 0);
	print_vector(vec);
	it += 30;
	vec.insert(it, -21);
	print_vector(vec);
	it = vec.begin() + 2;
	// vec.insert(it, 5, -1);
	// print_vector(vec);

	// Fill constructor
	ft::Vector<int> vec2(5, 3);
	vec2.push_back(3);
	vec2.push_back(3);
	vec2.push_back(3);
	// Insert range
	vec.insert(vec.begin(), vec2.begin(), vec2.end());
	print_vector(vec);
	
	// Max size
	std::vector<int> test;
	std::cout << "Max size: " << vec.max_size() << std::endl;
	std::cout << "Max size: " << test.max_size() << std::endl;

	// At
	std::cout << "vec[5]: " << vec.at(5) << std::endl;
	try {
		std::cout << "vec[50]: " << vec.at(50) << std::endl;
	} catch (std::exception &e) {
		std::cout << "exception: " << e.what() << std::endl;
	}
	try {
		std::cout << "vec[-1]: " << vec.at(-1) << std::endl;
	} catch (std::exception &e) {
		std::cout << "exception: " << e.what() << std::endl;
	}*/
	test_vector<ft::Vector<int> >();

	return (0);
}