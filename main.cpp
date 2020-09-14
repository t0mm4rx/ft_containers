#include "./include/Vector.hpp"
#include <iostream>

int main(void)
{
	ft::Vector<int>	vec;
	std::cout << (vec.begin() == vec.end()) << std::endl;
    return (0);
}