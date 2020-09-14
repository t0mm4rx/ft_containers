#include "./include/Vector.hpp"
#include <iostream>

void print_vector(ft::Vector<int> vec)
{
    ft::Vector<int>::iterator it;

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

int main(void)
{
	ft::Vector<int> vec;
	vec.push_back(4);
	vec.push_back(8);
	vec.push_back(42);
	vec.push_back(21);
	vec.push_back(-42);
	print_vector(vec);

	ft::Vector<int>::iterator it = vec.begin();
	it += 2;
	vec.insert(it, 0);
	print_vector(vec);
	it += 30;
	vec.insert(it, -21);
	print_vector(vec);
	return (0);
}