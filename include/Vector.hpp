#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <memory>
# include "VectorIterator.hpp"

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
								_container(nullptr),
								_allocator(allocator)
			{
				_container = _allocator.allocate(0);
			};
			explicit		Vector(size_type n, const_reference value = value_type(), const allocator_type &allocator = allocator_type())
							:	_container_length(0),
								_container_size(0),
								_container(nullptr),
								_allocator(allocator)
			{
				_container = _allocator.allocate(0);
				this->assign(n, value);
			};
			template <class InputIterator>
							Vector(InputIterator begin, InputIterator end, const allocator_type &allocator = allocator_type())
							:	_container_length(0),
								_container_size(0),
								_container(nullptr),
								_allocator(allocator)
			{
				_container = _allocator.allocate(0);
				this->assign(begin, end);
			};
							Vector(const Vector &other)
			{
				*this = other;
			};
							~Vector(void)
			{
			};
			void			assign(size_type n, const_reference value)
			{
				(void)n;
				(void)value;
			};
			template <class InputIterator>
			void			assign(InputIterator begin, InputIterator end)
			{
				(void)begin;
				(void)end;
			};
			reference		operator[](size_type n)
			{
				return (_container[n]);
			};
			iterator		begin(void)
			{
				return (iterator(_container));
			};
			iterator		end(void)
			{
				return (iterator(_container + _container_length));
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
	};
};

#endif