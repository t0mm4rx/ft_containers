#include "tests.hpp"

#include "../include/Queue.hpp"

void test_queue(void)
{
	ft::Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	std::cout << q.front() << std::endl;
	std::cout << q.back() << std::endl;
	q.pop();
	std::cout << q.front() << std::endl;
	std::cout << q.back() << std::endl;

	ft::Queue<int> s = q;
	
	std::cout << "q == s: " << (q == s) << std::endl;
	std::cout << "q != s: " << (q != s) << std::endl;
	std::cout << "q > s: " << (q > s) << std::endl;
	std::cout << "q < s: " << (q < s) << std::endl;
	std::cout << "q >= s: " << (q >= s) << std::endl;
	std::cout << "q <= s: " << (q <= s) << std::endl;

	std::cout << "Push 42 to q" << std::endl;
	q.push(42);

	std::cout << "q == s: " << (q == s) << std::endl;
	std::cout << "q != s: " << (q != s) << std::endl;
	std::cout << "q > s: " << (q > s) << std::endl;
	std::cout << "q < s: " << (q < s) << std::endl;
	std::cout << "q >= s: " << (q >= s) << std::endl;
	std::cout << "q <= s: " << (q <= s) << std::endl;
}