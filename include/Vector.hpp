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
			}
			iterator		end(void)
			{
				return (iterator(_container + _container_length));
			}
	};
};

#endif