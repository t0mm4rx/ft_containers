#ifndef LIST_HPP
# define LIST_HPP

# include <memory>
# include <limits>
# include "ListIterator.hpp"

namespace ft
{
	template <class T, class Alloc=std::allocator<T> >
	class List
	{
		public:
			typedef T value_type;
			typedef Alloc allocator_type;
			typedef T& reference;
			typedef const T& const_reference;
			typedef T* pointer;
			typedef const T* const_pointer;
			typedef unsigned long size_type;
			typedef Node<value_type>* node;
			typedef ListIterator<value_type> iterator;
		private:
			node _list_begin;
			node _list_end;
			allocator_type _allocator;
			size_t _length;
			Node<value_type> *_new_node(value_type value, Node<value_type> *prev, Node<value_type> *next)
			{
				node node = new Node<value_type>();
				node->data = value;
				node->prev = prev;
				node->next = next;
				return (node);
			};
			void _init_list(void)
			{
				_list_begin = _new_node(value_type(), 0, 0);
				_list_end = _new_node(value_type(), _list_begin, 0);
				_list_begin->next = _list_end;
			};
			struct _Smaller {
				bool operator()(const int &a, const int &b) {return a > b;}
			};
		public:
			explicit List(const allocator_type &alloc=allocator_type())
			: _list_begin(0), _list_end(0), _allocator(alloc), _length(0)
			{
				_init_list();
			};
			explicit List(size_type n, const value_type &value, const allocator_type &alloc=allocator_type())
			: _list_begin(0), _list_end(0), _allocator(alloc), _length(0)
			{
				_init_list();
				assign(n, value);
			};
			template <class InputIterator>
			List(InputIterator first, InputIterator last, const allocator_type &alloc=allocator_type())
			: _list_begin(0), _list_end(0), _allocator(alloc), _length(0)
			{
				_init_list();
				assign(first, last);
			};
			List(const List &other)
			: _list_begin(0), _list_end(0), _allocator(other._allocator), _length(0)
			{
				_init_list();
				*this = other;
			};
			~List(void)
			{
				clear();
				delete _list_begin;
				delete _list_end;
			};
			List &operator=(const List &other)
			{
				clear();
				assign(other.begin(), other.end());
				return (*this);
			};
			iterator begin(void) {
				return (iterator(_list_begin->next));
			};
			iterator begin(void) const {
				return (iterator(_list_begin->next));
			};
			iterator end(void) {
				return (iterator(_list_end));
			};
			iterator end(void) const {
				return (iterator(_list_end));
			};
			// reverse_iterator rbegin(void) {};
			// const_reverse_iterator rbegin(void) const {};
			// reverse_iterator rend(void) {};
			// const_reverse_iterator rend(void) const {};
			bool empty(void) const
			{
				return (_length == 0);
			};
			size_type size(void) const
			{
				return (_length);
			};
			size_type max_size(void) const
			{
				return (std::numeric_limits<size_type>::max() / (sizeof(Node<T>)));
			};
			reference front(void)
			{
				return (_list_begin->next->data);
			};
			const_reference front(void) const
			{
				return (_list_begin->next->data);
			};
			reference back(void)
			{
				return (_list_end->prev->data);
			};
			const_reference back(void) const
			{
				return (_list_end->prev->data);
			};
			template <class InputIterator>
			void assign(InputIterator first, InputIterator last)
			{
				while (first != last)
					push_back(*(first++));
			};
			void assign(size_type n, const value_type &value)
			{
				while (n--)
					push_back(value);
			};
			void push_front(const value_type &value)
			{
				node el = _new_node(value, _list_begin, _list_begin->next);
				_list_begin->next->prev = el;
				_list_begin->next = el;
				++_length;
			};
			void pop_front(void)
			{
				node next = _list_begin->next->next;
				delete _list_begin->next;
				_list_begin->next = next;
				next->prev = _list_begin;
			};
			void push_back(const value_type &value)
			{
				node el = _new_node(value, _list_end->prev, _list_end);
				_list_end->prev->next = el;
				_list_end->prev = el;
				++_length;
			}
			void pop_back(void)
			{
				node before = _list_end->prev->prev;
				delete _list_end->prev;
				before->next = _list_end;
				_list_end->prev = before;
			};
			// iterator insert(iterator position, const value_type &value)
			// {};
			// void insert(iterator position, const value_type &value)
			// {};
			// template <class InputIterator>
			// void insert(iterator position, InputIterator first, InputIterator last)
			// {};
			// iterator erase(iterator position)
			// {};
			// iterator erase(iterator first, iterator last)
			// {};
			void swap(List &x)
			{
				ft::swap(x._length, _length);
				ft::swap(x._list_begin, _list_begin);
				ft::swap(x._list_end, _list_end);
			};
			void resize(size_type n, value_type value = value_type())
			{
				(void)n;
				(void)value;
			};
			void clear(void)
			{
				node cur = _list_begin->next;
				while (cur != _list_end)
				{
					node next = cur->next;
					delete cur;
					cur = next;
				}
				_list_begin->next = _list_end;
				_list_end->prev = _list_begin;
			};
			// void splice(iterator position, List &x)
			// {};
			// void splice(iterator position, List &x, iterator i)
			// {};
			// void splice(iterator position, List &x, iterator first, iterator last)
			// {};
			void remove(const value_type &value)
			{
				(void)value;
			};
			template <class Predicate>
			void remove_if(Predicate pred)
			{
				(void)pred;
			};
			void unique(void)
			{};
			template <class BinaryPredicate>
			void unique(BinaryPredicate binary_pred)
			{
				(void)binary_pred;
			};
			void merge(List &x)
			{
				(void)x;
			};
			template <class Compare>
			void merge(List &x, Compare comp)
			{
				(void)x;
				(void)comp;
			};
			void sort(void)
			{
				sort(_Smaller());
			};
			template <class Compare>
			void sort(Compare comp)
			{
				iterator a = begin();
				iterator b;
				while (a + 1 != end())
				{
					b = a + 1;
					while (b != end())
					{
						if (comp(*a, *b))
							ft::swap(*a, *b);
						b++;
					}
					a++;
				}
			};
			void reverse(void)
			{
				List<value_type> tmp;
				iterator it = begin();
				while (it != end())
					tmp.push_front(*(it++));
				*this = tmp;
			};
	};
	template <class T, class Alloc>
	void swap(List<T, Alloc> &x, List<T, Alloc> &y)
	{
		x.swap(y);
	};
};

#endif