#ifndef TESTS_HPP
# define TESTS_HPP

# include <vector>
# include <list>
# include <map>
# include <stack>
# include <queue>
# include <iostream>
# include "../include/Vector.hpp"
# include "../include/List.hpp"
# include "../include/Map.hpp"
# include "../include/Queue.hpp"
# include "../include/Stack.hpp"

# ifdef __linux__
#  define RESET "\e[0m"
#  define GREEN "\e[92m"
#  define BLUE "\e[94m"
#  define BOLD "\e[1m"
# endif

# ifdef __APPLE__
#  define RESET "\e[0m"
#  define GREEN "\e[92m"
#  define BLUE "\e[94m"
#  define BOLD "\e[1m"
# endif

# define GOOD "✓"
# define FAIL "❌"

void	test_vector(void);
void	test_list(void);
void	test_map(void);
void	test_stack(void);
void	test_queue(void);

inline void print_header(std::string str)
{
	int margin = (30 - str.length()) / 2;
	int width = (margin * 2 + str.length()) + 2;
	std::cout << BLUE << std::endl;
	std::cout << std::string(width, '*') << std::endl;
	std::cout << "*" << std::string(margin, ' ') << str << std::string(margin, ' ') << "*" << std::endl;
	std::cout << std::string(width, '*') << std::endl;
	std::cout << RESET;
};

template <typename T>
inline void check(std::string name, T a, T b)
{
	if (a == b)
		std::cout << name << ": " << BOLD << GREEN << GOOD << RESET << std::endl;
	else
		std::cout << name << ": " << FAIL << std::endl;
};

inline void check(std::string name, bool good)
{
	if (good)
		std::cout << name << ": " << BOLD << GREEN << GOOD << RESET << std::endl;
	else
		std::cout << name << ": " << FAIL << std::endl;
};

template <typename T>
bool operator==(ft::Vector<T> &a, std::vector<T> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
			return (false);
	}
	return (true);
};

#endif