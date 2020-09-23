#include "tests.hpp"

static void constructors(void)
{
	print_header("Constructor");
	ft::Queue<int> q1;
	std::queue<int> q2;
	check("q1.size() == q2.size()", q1.size() == q2.size());
	check("q1.empty() == q2.empty()", q1.empty() == q2.empty());
}

static void front_back(void)
{
	print_header("Front / Back / Push / Pop");
	ft::Queue<int> q1;
	std::queue<int> q2;
	q1.push(0);
	q1.push(1);
	q1.push(2);
	q2.push(0);
	q2.push(1);
	q2.push(2);
	check("q1.size() == q2.size()", q1.size() == q2.size());
	check("q1.empty() == q2.empty()", q1.empty() == q2.empty());
	check("q1.front() == q2.front()", q1.front(), q2.front());
	check("q1.back() == q2.back()", q1.back(), q2.back());
	q1.pop();
	q2.pop();
	check("q1.size() == q2.size()", q1.size() == q2.size());
	check("q1.front() == q2.front()", q1.front(), q2.front());
	check("q1.back() == q2.back()", q1.back(), q2.back());
}

void test_queue(void)
{
	print_header("Queue");
	constructors();
	front_back();
}