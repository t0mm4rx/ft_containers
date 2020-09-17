#ifndef LISTITERATOR_HPP
# define LISTITERATOR_HPP

# include "List.hpp"
# include "Utils.hpp"

namespace ft
{
	template <class T>
	class ListIterator
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef Node<T>* pointer;
		protected:
			pointer _ptr;
		public:
			ListIterator(void)
			{};
			ListIterator(const ListIterator &other)
			{
				*this = other;
			};
			ListIterator(pointer ptr)
			: _ptr(ptr)
			{};
			~ListIterator(void)
			{};
			ListIterator &operator=(const ListIterator &other)
			{
				_ptr = other._ptr;
				return (*this);
			};
			ListIterator &operator++(void)
			{
				_ptr = _ptr->next;
				return (*this);
			};
			ListIterator &operator--(void)
			{
				_ptr = _ptr->prev;
				return (*this);
			};
			ListIterator operator++(int)
			{
				ListIterator tmp(*this);
				operator++();
				return (tmp);
			};
			ListIterator operator--(int)
			{
				ListIterator tmp(*this);
				operator--();
				return (tmp);
			};
			bool operator==(const ListIterator &other) const
			{
				return (_ptr == other._ptr);
			};
			bool operator!=(const ListIterator &other) const
			{
				return (_ptr != other._ptr);
			};
			bool operator>(const ListIterator &other) const
			{
				return (_ptr > other._ptr);
			};
			bool operator>=(const ListIterator &other) const
			{
				return (_ptr >= other._ptr);
			};
			bool operator<(const ListIterator &other) const
			{
				return (_ptr < other._ptr);
			};
			bool operator<=(const ListIterator &other) const
			{
				return (_ptr <= other._ptr);
			};
			value_type &operator*(void)
			{
				return (_ptr->data);
			};
			value_type *operator->(void)
			{
				return (_ptr->data);
			};
			ListIterator operator+(int n) const
			{
				ListIterator tmp(*this);
				tmp += n;
				return (tmp);
			};
			ListIterator operator-(int n) const
			{
				ListIterator tmp(*this);
				tmp -= n;
				return (tmp);
			};
			ListIterator &operator+=(int n)
			{
				while (n < 0)
				{
					(*this)--;
					n++;
				}
				while (n > 0)
				{
					(*this)++;
					n--;
				}
				return (*this);
			};
			ListIterator &operator-=(int n)
			{
				while (n > 0)
				{
					operator--();
					n--;
				}
				while (n < 0)
				{
					operator++();
					n++;
				}
				return (*this);
			};
	};
};

#endif