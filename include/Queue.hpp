#ifndef QUEUE_HPP
# define QUEUE_HPP

#include "List.hpp"

namespace ft
{
	template <class T, class Container = ft::List<T> >
	class Queue
	{
		public:
			typedef T value_type;
			typedef Container container_type;
			typedef unsigned long size_type;
		protected:
			container_type c;
		public:
			explicit Queue(const container_type &ctnr = container_type())
			: c(ctnr)
			{};
			Queue(const Queue &other)
			{
				*this = other;
			};
			~Queue(void)
			{};
			Queue &operator=(const Queue &other)
			{
				this->c = other.c;
				return (*this);
			};
			bool empty(void) const
			{
				return (c.empty());
			};
			size_type size(void) const
			{
				return (c.size());
			};
			value_type &front(void)
			{
				return (c.front());
			};
			const value_type &front(void) const
			{
				return (c.front());
			};
			value_type &back(void)
			{
				return (c.back());
			};
			const value_type &back(void) const
			{
				return (c.back());
			};
			void push(const value_type &value)
			{
				return (c.push_back(value));
			};
			void pop(void)
			{
				c.pop_front();
			};
			private:
				template <class A, class B>
				friend bool	operator==(const Queue<A, B> &lhs, const Queue<A, B> &rhs);
				template <class A, class B>
				friend bool	operator!=(const Queue<A, B> &lhs, const Queue<A, B> &rhs);
				template <class A, class B>
				friend bool	operator<(const Queue<A, B> &lhs, const Queue<A, B> &rhs);
				template <class A, class B>
				friend bool	operator<=(const Queue<A, B> &lhs, const Queue<A, B> &rhs);
				template <class A, class B>
				friend bool	operator>(const Queue<A, B> &lhs, const Queue<A, B> &rhs);
				template <class A, class B>
				friend bool	operator>=(const Queue<A, B> &lhs, const Queue<A, B> &rhs);
	};
	template <class T, class Container>
	bool operator==(const Queue<T, Container> &lhs, const Queue<T, Container> &rhs)
	{
		return (lhs.c == rhs.c);
	};
	template <class T, class Container>
	bool operator!=(const Queue<T, Container> &lhs, const Queue<T, Container> &rhs)
	{
		return (lhs.c != rhs.c);
	};
	template <class T, class Container>
	bool operator>(const Queue<T, Container> &lhs, const Queue<T, Container> &rhs)
	{
		return (lhs.c > rhs.c);
	};
	template <class T, class Container>
	bool operator<(const Queue<T, Container> &lhs, const Queue<T, Container> &rhs)
	{
		return (lhs.c < rhs.c);
	};
	template <class T, class Container>
	bool operator>=(const Queue<T, Container> &lhs, const Queue<T, Container> &rhs)
	{
		return (lhs.c >= rhs.c);
	};
	template <class T, class Container>
	bool operator<=(const Queue<T, Container> &lhs, const Queue<T, Container> &rhs)
	{
		return (lhs.c <= rhs.c);
	};
};

#endif