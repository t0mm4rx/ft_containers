#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

namespace ft
{
	template <class T>
	class VectorIterator
	{
		public:
			typedef			T value_type;
			typedef			T& reference;
			typedef			T*	pointer;
		private:
			pointer			_ptr;
		public:
							VectorIterator(void)
			{};
							VectorIterator(const VectorIterator &other)
			{
				*this = other;
			};
							VectorIterator(pointer ptr)
							: _ptr(ptr)
			{};
							~VectorIterator(void)
			{};
			VectorIterator	&operator=(const VectorIterator &other)
			{
				this->_ptr = other._ptr;
				return (*this);
			};
			VectorIterator	&operator++(void)
			{
				this->_ptr++;
				return (*this);
			};
			VectorIterator	&operator--(void)
			{
				this->_ptr--;
				return (*this);
			};
			VectorIterator	operator++(int)
			{
				VectorIterator	tmp(*this);
				*this++;
				return (tmp);
			};
			VectorIterator	operator--(int)
			{
				VectorIterator	tmp(*this);
				*this--;
				return (tmp);
			};
			bool			operator==(const VectorIterator &other) const
			{
				return (this->_ptr == other._ptr);
			};
			bool			operator!=(const VectorIterator &other) const
			{
				return (this->_ptr != other._ptr);
			};
			bool			operator>(const VectorIterator &other) const
			{
				return (this->_ptr > other._ptr);
			};
			bool			operator>=(const VectorIterator &other) const
			{
				return (this->_ptr >= other._ptr);
			};
			bool			operator<(const VectorIterator &other) const
			{
				return (this->_ptr < other._ptr);
			};
			bool			operator<=(const VectorIterator &other) const
			{
				return (this->_ptr <= other._ptr);
			};
			value_type		&operator*(void)
			{
				return (*this->_ptr);
			};
			value_type		*operator->(void)
			{
				return (this->_ptr);
			};
			VectorIterator	operator+(int n) const
			{
				VectorIterator tmp(*this);
				tmp += n;
				return (tmp);
			};
			VectorIterator	operator-(int n) const
			{
				VectorIterator tmp(*this);
				tmp -= n;
				return (tmp);
			};
			VectorIterator	&operator+=(int n)
			{
				while (n < 0)
				{
					*this--;
					n++;
				}
				while (n > 0)
				{
					*this++;
					n--;
				}
				return (*this);
			};
			VectorIterator	&operator-=(int n)
			{
				while (n < 0)
				{
					*this--;
					n--;
				}
				while (n > 0)
				{
					*this++;
					n++;
				}
				return (*this);
			};
			value_type		&operator[](int n) const
			{
				return (*(*this + n));
			}
	};
};

#endif