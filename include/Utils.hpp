#ifndef UTILS_HPP
# define UTILS_HPP

# include "Utils.hpp"

namespace ft
{
	template <typename T>
	void	swap(T &a, T &b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	};
	template <class T>
	struct Node
	{
		T data;
		Node *prev;
		Node *next;
	};
	template <class Key, class T>
	struct BNode
	{
		bool root;
		Key key;
		T value;
		BNode *left;
		BNode *right;
	};
};

#endif