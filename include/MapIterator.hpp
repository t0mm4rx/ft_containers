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
		private:
			pointer _successor(pointer ptr)
			{
				pointer next;
				if (!ptr->right)
				{
					next = ptr;
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = ptr->right;
					while (next->left)
						next = next->left;
				}
				return (next);
			};
			pointer _predecessor(pointer ptr)
			{
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
				return (next);
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
			bool operator>(const MapIterator<K, T> &other)
			{
				return (_ptr > other._ptr);
			};
			bool operator<(const MapIterator<K, T> &other)
			{
				return (_ptr < other._ptr);
			};
			bool operator>=(const MapIterator<K, T> &other)
			{
				return (_ptr >= other._ptr);
			};
			bool operator<=(const MapIterator<K, T> &other)
			{
				return (_ptr <= other._ptr);
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
	template <class K, class T>
	class ConstMapIterator
	{
		public:
			typedef std::pair<K, T> value_type;
			typedef std::pair<K, T>& reference;
			typedef BNode<K, T>* pointer;
		protected:
			pointer _ptr;
		private:
			pointer _successor(pointer ptr)
			{
				pointer next;
				if (!ptr->right)
				{
					next = ptr;
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = ptr->right;
					while (next->left)
						next = next->left;
				}
				return (next);
			};
			pointer _predecessor(pointer ptr)
			{
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
				return (next);
			};
		public:
			ConstMapIterator(void)
			: _ptr(0)
			{};
			ConstMapIterator(const pointer ptr)
			: _ptr(ptr)
			{};
			ConstMapIterator(const ConstMapIterator &other)
			{
				*this = other;
			};
			ConstMapIterator &operator=(const ConstMapIterator &other)
			{
				_ptr = other._ptr;
				return (*this);
			};
			pointer node(void)
			{
				return (_ptr);
			};
			value_type &operator*(void) const
			{
				return (_ptr->pair);
			};
			value_type *operator->(void) const
			{
				return (&_ptr->pair);
			};
			bool operator==(const ConstMapIterator<K, T> &other)
			{
				return (_ptr == other._ptr);
			};
			bool operator!=(const ConstMapIterator<K, T> &other)
			{
				return (!(*this == other));
			};
			bool operator>(const ConstMapIterator<K, T> &other)
			{
				return (_ptr > other._ptr);
			};
			bool operator<(const ConstMapIterator<K, T> &other)
			{
				return (_ptr < other._ptr);
			};
			bool operator>=(const ConstMapIterator<K, T> &other)
			{
				return (_ptr >= other._ptr);
			};
			bool operator<=(const ConstMapIterator<K, T> &other)
			{
				return (_ptr <= other._ptr);
			};
			ConstMapIterator &operator++(void)
			{
				_ptr = _successor(_ptr);
				return (*this);
			};
			ConstMapIterator &operator--(void)
			{
				_ptr = _predecessor(_ptr);
				return (*this);
			};
			ConstMapIterator operator++(int)
			{
				ConstMapIterator tmp(*this);
				this->operator++();
				return (tmp);
			};
			ConstMapIterator operator--(int)
			{
				ConstMapIterator tmp(*this);
				this->operator--();
				return (tmp);
			};
	};
	template <class K, class T>
	class ReverseMapIterator
	{
		public:
			typedef std::pair<K, T> value_type;
			typedef std::pair<K, T>& reference;
			typedef BNode<K, T>* pointer;
		protected:
			pointer _ptr;
		private:
			pointer _successor(pointer ptr)
			{
				pointer next;
				if (!ptr->right)
				{
					next = ptr;
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = ptr->right;
					while (next->left)
						next = next->left;
				}
				return (next);
			};
			pointer _predecessor(pointer ptr)
			{
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
				return (next);
			};
		public:
			ReverseMapIterator(void)
			: _ptr(0)
			{};
			ReverseMapIterator(const pointer ptr)
			: _ptr(ptr)
			{};
			ReverseMapIterator(const ReverseMapIterator &other)
			{
				*this = other;
			};
			ReverseMapIterator &operator=(const ReverseMapIterator &other)
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
			bool operator==(const ReverseMapIterator<K, T> &other)
			{
				return (_ptr == other._ptr);
			};
			bool operator!=(const ReverseMapIterator<K, T> &other)
			{
				return (!(*this == other));
			};
			bool operator>(const ReverseMapIterator<K, T> &other)
			{
				return (_ptr > other._ptr);
			};
			bool operator<(const ReverseMapIterator<K, T> &other)
			{
				return (_ptr < other._ptr);
			};
			bool operator>=(const ReverseMapIterator<K, T> &other)
			{
				return (_ptr >= other._ptr);
			};
			bool operator<=(const ReverseMapIterator<K, T> &other)
			{
				return (_ptr <= other._ptr);
			};
			ReverseMapIterator &operator++(void)
			{
				_ptr = _predecessor(_ptr);
				return (*this);
			};
			ReverseMapIterator &operator--(void)
			{
				_ptr = _successor(_ptr);
				return (*this);
			};
			ReverseMapIterator operator++(int)
			{
				ReverseMapIterator tmp(*this);
				this->operator++();
				return (tmp);
			};
			ReverseMapIterator operator--(int)
			{
				ReverseMapIterator tmp(*this);
				this->operator--();
				return (tmp);
			};
	};
	template <class K, class T>
	class ConstReverseMapIterator
	{
		public:
			typedef std::pair<K, T> value_type;
			typedef std::pair<K, T>& reference;
			typedef BNode<K, T>* pointer;
		protected:
			pointer _ptr;
		private:
			pointer _successor(pointer ptr)
			{
				pointer next;
				if (!ptr->right)
				{
					next = ptr;
					while (next->parent && next == next->parent->right)
						next = next->parent;
					next = next->parent;
				}
				else
				{
					next = ptr->right;
					while (next->left)
						next = next->left;
				}
				return (next);
			};
			pointer _predecessor(pointer ptr)
			{
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
				return (next);
			};
		public:
			ConstReverseMapIterator(void)
			: _ptr(0)
			{};
			ConstReverseMapIterator(const pointer ptr)
			: _ptr(ptr)
			{};
			ConstReverseMapIterator(const ConstReverseMapIterator &other)
			{
				*this = other;
			};
			ConstReverseMapIterator &operator=(const ConstReverseMapIterator &other)
			{
				_ptr = other._ptr;
				return (*this);
			};
			pointer node(void)
			{
				return (_ptr);
			};
			value_type &operator*(void) const
			{
				return (_ptr->pair);
			};
			value_type *operator->(void) const
			{
				return (&_ptr->pair);
			};
			bool operator==(const ConstReverseMapIterator<K, T> &other)
			{
				return (_ptr == other._ptr);
			};
			bool operator!=(const ConstReverseMapIterator<K, T> &other)
			{
				return (!(*this == other));
			};
			bool operator>(const ConstReverseMapIterator<K, T> &other)
			{
				return (_ptr > other._ptr);
			};
			bool operator<(const ConstReverseMapIterator<K, T> &other)
			{
				return (_ptr < other._ptr);
			};
			bool operator>=(const ConstReverseMapIterator<K, T> &other)
			{
				return (_ptr >= other._ptr);
			};
			bool operator<=(const ConstReverseMapIterator<K, T> &other)
			{
				return (_ptr <= other._ptr);
			};
			ConstReverseMapIterator &operator++(void)
			{
				_ptr = _predecessor(_ptr);
				return (*this);
			};
			ConstReverseMapIterator &operator--(void)
			{
				_ptr = _successor(_ptr);
				return (*this);
			};
			ConstReverseMapIterator operator++(int)
			{
				ConstReverseMapIterator tmp(*this);
				this->operator++();
				return (tmp);
			};
			ConstReverseMapIterator operator--(int)
			{
				ConstReverseMapIterator tmp(*this);
				this->operator--();
				return (tmp);
			};
	};
};

#endif