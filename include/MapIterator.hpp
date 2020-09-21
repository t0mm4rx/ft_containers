#ifndef MAPITERATOR_HPP
# define MAPITERATOR_HPP
# include "Utils.hpp"
# include <utility>

namespace ft
{
	template <class K, class T>
	class MapIterator
	{
		public:
			typedef std::pair<K, T> value_type;
			typedef std::pair<K, T>& reference;
			typedef BNode<K, T>* pointer;
		protected:
			pointer _ptr;
			pointer _last;
		private:
			pointer _root(pointer ptr)
			{
				while (ptr->parent)
					ptr = ptr->parent;
				return (ptr);
			};
			pointer _min_value(pointer ptr)
			{
				while (ptr->left)
					ptr = ptr->left;
				return (ptr);
			};
			pointer _max_value(pointer ptr)
			{
				while (ptr->right)
					ptr = ptr->right;
				return (ptr);
			};
			pointer _successor(pointer ptr)
			{
				_last = ptr;
				if (ptr->right)
					return (ptr->right);
				pointer p = ptr->parent;
				while (p && ptr == p->right)
				{
					ptr = p;
					p = p->parent;
				}
				return (p);
			};
			pointer _predecessor(pointer ptr)
			{
				if (!ptr)
				{
					std::cout << "Here" << std::endl;
					return (_last);
				}
				_last = ptr;
				pointer next;

				if (!ptr->left)
				{
					next = ptr;
					while (next->parent && next == next->parent->left)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = ptr->left;
					while (next->right)
						next = next->right;
				}
				ptr = next;
				return (ptr);
			};
		public:
			MapIterator(void)
			: _ptr(0)
			{};
			MapIterator(const pointer ptr)
			: _ptr(ptr)
			{};
			MapIterator(const MapIterator &other)
			{
				*this = other;
			};
			MapIterator &operator=(const MapIterator &other)
			{
				_ptr = other._ptr;
				return (*this);
			};
			pointer node(void)
			{
				return (_ptr);
			};
			value_type &operator*(void)
			{
				return (_ptr->pair);
			};
			value_type *operator->(void)
			{
				return (&_ptr->pair);
			};
			bool operator==(const MapIterator<K, T> &other)
			{
				return (_ptr == other._ptr);
			};
			bool operator!=(const MapIterator<K, T> &other)
			{
				return (!(*this == other));
			};
			MapIterator &operator++(void)
			{
				_ptr = _successor(_ptr);
				return (*this);
			};
			MapIterator &operator--(void)
			{
				_ptr = _predecessor(_ptr);
				return (*this);
			};
			MapIterator operator++(int)
			{
				MapIterator tmp(*this);
				this->operator++();
				return (tmp);
			};
			MapIterator operator--(int)
			{
				MapIterator tmp(*this);
				this->operator--();
				return (tmp);
			};
	};
};

#endif