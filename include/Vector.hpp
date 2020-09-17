#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include <limits>
# include "VectorIterator.hpp"
# include "Utils.hpp"

namespace ft
{
	template <typename T, typename A = std::allocator<T> >
	class Vector
	{
		public:
			typedef			T value_type;
			typedef			A allocator_type;
			typedef			T& reference;
			typedef			const T& const_reference;
			typedef			T* pointer;
			typedef			const T* const_pointer;
			typedef			ft::VectorIterator<T> iterator;
			typedef			ft::ConstVectorIterator<T> const_iterator;
			typedef			ft::ReverseVectorIterator<T> reverse_iterator;
			typedef			ft::ConstReverseVectorIterator<T> const_reverse_iterator;
			typedef			unsigned long size_type;
		private:
			size_type		_container_length;
			size_type		_container_size;
			pointer			_container;
			allocator_type	_allocator;
		public:
			explicit		Vector(const allocator_type &allocator = allocator_type())
							:	_container_length(0),
								_container_size(0),
								_container(0),
								_allocator(allocator)
			{
				_container = _allocator.allocate(0);
			};
			template <class InputIterator>
							Vector(InputIterator begin, InputIterator end, const allocator_type &allocator = allocator_type())
							:	_container_length(0),
								_container_size(0),
								_container(0),
								_allocator(allocator)
			{
				_container = _allocator.allocate(0);
				assign(begin, end);
			};
							Vector(size_type n, const_reference value = value_type(), const allocator_type &allocator = allocator_type())
							:	_container_length(0),
								_container_size(0),
								_container(0),
								_allocator(allocator)
			{
				_container = _allocator.allocate(0);
				assign(n, value);
			};
							Vector(const Vector &other)
							:	_container_length(0),
								_container_size(0),
								_container(0),
								_allocator(other._allocator)
			{
				*this = other;
			};
							~Vector(void)
			{
				_allocator.deallocate(_container, _container_size);
			};
			Vector			&operator=(const Vector &other)
			{
				if (_container != 0)
					_allocator.deallocate(_container, _container_size);
				_allocator = other._allocator;
				_container_size = 0;
				_container_length = 0;
				_container = _allocator.allocate(0);
				assign(other.begin(), other.end());
				return (*this);
			};
			reference		operator[](size_type n)
			{
				return (_container[n]);
			};
			const_reference	operator[](size_type n) const
			{
				return (_container[n]);
			};
			iterator		begin(void)
			{
				return (iterator(_container));
			};
			const_iterator	begin(void) const
			{
				return (const_iterator(_container));
			};
			iterator		end(void)
			{
				return (iterator(_container + _container_length));
			};
			const_iterator		end(void) const
			{
				return (const_iterator(_container + _container_length));
			};
			reverse_iterator
							rbegin(void)
			{
				return (reverse_iterator(_container + _container_length - 1));
			};
			const_reverse_iterator
							rbegin(void) const
			{
				return (const_reverse_iterator(_container + _container_length - 1));
			};
			reverse_iterator
							rend(void)
			{
				return (reverse_iterator(_container - 1));
			};
			const_reverse_iterator
							rend(void) const
			{
				return (const_reverse_iterator(_container - 1));
			};
			void			reserve(size_type n)
			{
				if (n > _container_size)
				{
					size_type i = -1;
					pointer	tmp;
					tmp  = _allocator.allocate(n);
					_container_size = n;
					while (++i < _container_length)
						tmp[i] = _container[i];
					_allocator.deallocate(_container, _container_size);
					_container = tmp;
				}
			};
			void			push_back(const value_type &value)
			{
				if (_container_length + 1 > _container_size)
					reserve(_container_length + 1);
				_container[_container_length++] = value;
			};
			size_type		size(void) const
			{
				return (_container_length);
			};
			size_type		capacity(void) const
			{
				return (_container_size);
			};
			bool			empty(void) const
			{
				return (_container_length == 0);
			};
			iterator		insert(iterator position, const value_type &value)
			{
				size_type i = 0;
				iterator it = begin();
				while (it + i != position && i < _container_length)
					i++;
				if (_container_size < _container_length + 1)
					reserve(_container_length + 1);
				size_type j = _container_size - 1;
				while (j > i)
				{
					_container[j] = _container[j - 1];
					j--;
				}
				_container[i] = value;
				_container_length++;
				return (iterator(&_container[i]));
			};
			void			insert(iterator position, size_type n, const value_type &value)
			{
				while (n--)
					position = insert(position, value);
			};
			template <class InputIterator>
			void			insert(iterator position, InputIterator begin, InputIterator end)
			{
				while (begin != end)
					position = insert(position, *(begin++)) + 1;
			};
			size_type		max_size(void) const
			{
				return (std::numeric_limits<size_type>::max() / sizeof(value_type));
			};
			reference		at(size_type n)
			{
				if (n >= _container_length || n < 0)
					throw std::length_error("index out-of-bounds");
				return _container[n];
			};
			const_reference	at(size_type n) const
			{
				if (n >= _container_length || n < 0)
					throw std::length_error("index out-of-bounds");
				return _container[n];
			};
			iterator		erase(iterator position)
			{
				iterator cursor = position;
				while (cursor + 1 != end())
				{
					*cursor = *(cursor + 1);
					cursor++;
				}
				_container_length--;
				return (iterator(position));
			};
			iterator		erase(iterator begin, iterator end)
			{
				while (begin != end)
				{
					erase(begin);
					end--;
				}
				return (iterator(begin));
			};
			void			clear(void)
			{
				erase(begin(), end());
			};
			template <class InputIterator>
			void			assign(InputIterator first, InputIterator last)
			{
				clear();
				insert(begin(), first, last);
			};
			void			assign(size_type n, const value_type &value)
			{
				clear();
				insert(begin(), n, value);
			};
			reference		front(void)
			{
				return _container[0];
			};
			const_reference	front(void) const
			{
				return _container[0];
			};
			reference		back(void)
			{
				return _container[_container_length - 1];
			};
			const_reference	back(void) const
			{
				return _container[_container_length - 1];
			};
			void			pop_back(void)
			{
				if (_container_length)
					_container_length--;
			};
			void			resize(size_type n, value_type value = value_type())
			{
				while (n < _container_length)
					pop_back();
				while (n > _container_length)
					push_back(value);
			};
			void			swap(Vector &other)
			{
				ft::swap(_container, other._container);
				ft::swap(_container_size, other._container_size);
				ft::swap(_container_length, other._container_length);
			};
	};
	template <class T, class Alloc>
	void					swap(Vector<T, Alloc> &x, Vector<T, Alloc> &y)
	{
		x.swap(y);
	};
	template<class T, class Alloc>
	bool					operator==(const Vector<T, Alloc> &a, const Vector<T, Alloc> &b)
	{
		if (a.size() != b.size())
			return (false);
		unsigned long i = -1;
		while (++i < a.size())
		{
			if (a[i] != b[i])
				return (false);
		}
		return (true);
	};
	template<class T, class Alloc>
	bool					operator!=(const Vector<T, Alloc> &a, const Vector<T, Alloc> &b)
	{
		return (!(a == b));
	};
	template <class T, class Alloc>
	bool					operator<(const Vector<T,Alloc> &a, const Vector<T,Alloc> &b)
	{
		size_t		i;
		size_t		n;

		if (a.size() > b.size())
			n = b.size();
		else
			n = a.size();
		i = 0;
		while (i < n)
		{
			if (a.at(i) != b.at(i))
				return (a.at(i) < b.at(i));
			i++;
		}
		return (a.size() < b.size());
	}

	template <class T, class Alloc>
	bool					operator<=(const Vector<T,Alloc> &a, const Vector<T,Alloc> &b)
	{
		return (a < b || a == b);
	}

	template <class T, class Alloc>
	bool					operator>(const Vector<T,Alloc> &a, const Vector<T,Alloc> &b)
	{
		return (!(a < b) && !(a == b));
	}

	template <class T, class Alloc>
	bool					operator>=(const Vector<T,Alloc> &a, const Vector<T,Alloc> &b)
	{
		return (!(a < b));
	}
};

#endif