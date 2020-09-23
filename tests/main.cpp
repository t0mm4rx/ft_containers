#include "./tests.hpp"
#include "../include/Vector.hpp"
#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
	std::string choice;
	if (argc != 2)
	{
		std::cout << "No test given, testing vector." << std::endl;
		choice = "vector";
	}
	else
		choice = std::string(argv[1]);
	if (choice == "vector")
		test_vector();
	else if (choice == "list")
		test_list();
	else if (choice == "map")
		test_map();
	else if (choice == "stack")
		test_stack();
	else if (choice == "queue")
		test_queue();
	else
		std::cout << "No test for " << choice << std::endl;

	return (0);
}