#include "tests.hpp"

#include <stack>
#include "../include/Stack.hpp"

void test_stack(void)
{
	ft::Stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
	s.pop();
	std::cout << s.top() << std::endl;
	s.pop();

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	ft::Stack<int> a = s;

	std::cout << "a == s: " << (a == s) << std::endl;
	std::cout << "a != s: " << (a != s) << std::endl;
	std::cout << "a > s: " << (a > s) << std::endl;
	std::cout << "a < s: " << (a < s) << std::endl;
	std::cout << "a >= s: " << (a >= s) << std::endl;
	std::cout << "a <= s: " << (a <= s) << std::endl;

	std::cout << "Push 42 to a" << std::endl;
	a.push(42);

	std::cout << "a == s: " << (a == s) << std::endl;
	std::cout << "a != s: " << (a != s) << std::endl;
	std::cout << "a > s: " << (a > s) << std::endl;
	std::cout << "a < s: " << (a < s) << std::endl;
	std::cout << "a >= s: " << (a >= s) << std::endl;
	std::cout << "a <= s: " << (a <= s) << std::endl;
}