#include "./tests.hpp"

template <typename T>
void print_vector(T vec)
{
	typename T::iterator it;

	std::cout << "size " << vec.size() << ": ";
	it = vec.begin();
	while (it != vec.end())
	{
		std::cout << *it;
		if (it + 1 != vec.end())
			std::cout << " - ";
		++it;
	}
	std::cout << std::endl;
}

template <typename T>
void print_vector_reverse(T vec)
{
	typename T::reverse_iterator it;

	std::cout << "size " << vec.size() << ": ";
	it = vec.rbegin();
	while (it != vec.rend())
	{
		std::cout << *it;
		if (it + 1 != vec.rend())
			std::cout << " - ";
		++it;
	}
	std::cout << std::endl;
}

void	test_vector(void)
{
	// Default constructor
	ft::Vector<int> vec;
	std::vector<int> test;
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

	// Fill constructor
	ft::Vector<int> vec2((size_t)5, 3);
	// Insert range
	vec.insert(vec.begin(), vec2.begin(), vec2.end());
	print_vector(vec);
	
	// Max size
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
	}
	
	print_vector(vec);
	// Remove single element
	vec.erase(vec.begin() + 2);
	print_vector(vec);
	std::cout << "Capacity: " << vec.capacity() << std::endl;
	// Remove range
	vec.erase(vec.begin(), vec.begin() + 3);
	print_vector(vec);
	vec.erase(vec.end() - 2, vec.end());
	print_vector(vec);

	// Clear
	vec.clear();
	print_vector(vec);
	std::cout << "Capacity: " << vec.capacity() << std::endl;

	// Assign range
	test.push_back(1);
	test.push_back(2);
	test.push_back(3);
	test.push_back(4);
	print_vector(test);
	vec.assign(test.begin(), test.end());
	print_vector(vec);

	// Front/Back
	std::cout << "Front: " << vec.front() << std::endl;
	std::cout << "Back: " << vec.back() << std::endl;

	// pop_back
	print_vector(vec);
	vec.pop_back();
	print_vector(vec);

	// resize
	vec.resize(2, 0);
	print_vector(vec);
	vec.resize(10, 42);
	print_vector(vec);

	// = operator
	ft::Vector<int> vec3 = vec;
	print_vector(vec3);
	vec3 = vec2;
	print_vector(vec3);
	
	// Copy contsructor
	ft::Vector<int> vec4(vec);
	print_vector(vec4);

	// swap
	std::cout << "First swap: " << std::endl;
	vec4.swap(vec3);
	print_vector(vec3);
	print_vector(vec4);
	std::cout << "Second swap: " << std::endl;
	swap(vec3, vec4);
	print_vector(vec3);
	print_vector(vec4);

	// Reverse iterator
	std::cout << "Reverse iterator:" << std::endl;
	print_vector_reverse(vec4);

	// Const iterator
	std::cout << "Const iterator:" << std::endl;
	ft::Vector<int>::const_iterator cit = const_cast<const ft::Vector<int>& >(vec4).begin();
	std::cout << *cit << std::endl;
	cit++;
	std::cout << *cit << std::endl;
	cit += 3;
	std::cout << *cit << std::endl;

	// Const revserse iterator
	std::cout << "Const reverse iterator:" << std::endl;
	ft::Vector<int>::const_reverse_iterator crit = const_cast<const ft::Vector<int>& >(vec4).rbegin();
	std::cout << *crit << std::endl;
	crit += 8;
	std::cout << *crit << std::endl;
	crit++;
	std::cout << *crit << std::endl;

	// Operator ==
	std::cout << "vec4 == vec: " << (vec4 == vec) << std::endl;
	vec4.push_back(2);
	std::cout << "vec4 == vec: " << (vec4 == vec) << std::endl;
	vec = vec4;
	std::cout << "vec4 == vec: " << (vec4 == vec) << std::endl;
	vec[3] = -1;
	std::cout << "vec4 == vec: " << (vec4 == vec) << std::endl;
	vec.clear();
	vec4.clear();
	std::cout << "vec4 == vec: " << (vec4 == vec) << std::endl;

	// Operator >, <
	vec.push_back(1);
	std::cout << "vec4 > vec: " << (vec4 > vec) << std::endl;
	std::cout << "vec4 < vec: " << (vec4 < vec) << std::endl;
	vec4.push_back(2);
	std::cout << "vec4 > vec: " << (vec4 > vec) << std::endl;
	std::cout << "vec4 < vec: " << (vec4 < vec) << std::endl;
}