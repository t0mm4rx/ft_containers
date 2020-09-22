#ifndef VECTORITERATOR_HPP
# define VECTORITERATOR_HPP

namespace ft
{
	template <class T>
	class VectorIterator
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
		protected:
			pointer _ptr;
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
			VectorIterator &operator=(const VectorIterator &other)
			{
				_ptr = other._ptr;
				return (*this);
			};
			VectorIterator &operator++(void)
			{
				_ptr++;
				return (*this);
			};
			VectorIterator &operator--(void)
			{
				_ptr--;
				return (*this);
			};
			VectorIterator operator++(int)
			{
				VectorIterator tmp(*this);
				operator++();
				return (tmp);
			};
			VectorIterator operator--(int)
			{
				VectorIterator tmp(*this);
				operator--();
				return (tmp);
			};
			bool operator==(const VectorIterator &other) const
			{
				return (_ptr == other._ptr);
			};
			bool operator!=(const VectorIterator &other) const
			{
				return (_ptr != other._ptr);
			};
			bool operator>(const VectorIterator &other) const
			{
				return (_ptr > other._ptr);
			};
			bool operator>=(const VectorIterator &other) const
			{
				return (_ptr >= other._ptr);
			};
			bool operator<(const VectorIterator &other) const
			{
				return (_ptr < other._ptr);
			};
			bool operator<=(const VectorIterator &other) const
			{
				return (_ptr <= other._ptr);
			};
			value_type &operator*(void)
			{
				return (*_ptr);
			};
			value_type *operator->(void)
			{
				return (_ptr);
			};
			VectorIterator operator+(int n) const
			{
				VectorIterator tmp(*this);
				tmp += n;
				return (tmp);
			};
			VectorIterator operator-(int n) const
			{
				VectorIterator tmp(*this);
				tmp -= n;
				return (tmp);
			};
			VectorIterator &operator+=(int n)
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
			VectorIterator &operator-=(int n)
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
			value_type &operator[](int n) const
			{
				return (*(*this + n));
			}
	};
	template <class T>
	class ReverseVectorIterator : public VectorIterator<T>
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
			ReverseVectorIterator(void)
			{};
			ReverseVectorIterator(const ReverseVectorIterator &other)
			{
				*this = other;
			};
			ReverseVectorIterator(pointer ptr)
			{
				this->_ptr = ptr;
			};
			~ReverseVectorIterator(void)
			{};
			ReverseVectorIterator &operator=(const ReverseVectorIterator &other)
			{
				this->_ptr = other._ptr;
				return (*this);
			};
			ReverseVectorIterator &operator++(void)
			{
				this->_ptr--;
				return (*this);
			};
			ReverseVectorIterator operator++(int)
			{
				ReverseVectorIterator tmp(*this);
				this->_ptr--;
				return (tmp);
			};
			ReverseVectorIterator &operator--(void)
			{
				this->_ptr++;
				return (*this);
			};
			ReverseVectorIterator operator--(int)
			{
				ReverseVectorIterator tmp(*this);
				tmp._ptr++;
				rteurn (tmp);
			};
			ReverseVectorIterator operator+=(int n)
			{
				while (n > 0)
				{
					operator++();
					n--;
				}
				while (n < 0)
				{
					operator--();
					n++;
				}
				return (*this);
			};
			ReverseVectorIterator operator-=(int n)
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
			bool operator==(const ReverseVectorIterator &other) const
			{
				return (this->_ptr == other._ptr);
			};
			bool operator!=(const ReverseVectorIterator &other) const
			{
				return (this->_ptr != other._ptr);
			};
			bool operator>(const ReverseVectorIterator &other) const
			{
				return (this->_ptr > other._ptr);
			};
			bool operator>=(const ReverseVectorIterator &other) const
			{
				return (this->_ptr >= other._ptr);
			};
			bool operator<(const ReverseVectorIterator &other) const
			{
				return (this->_ptr < other._ptr);
			};
			bool operator<=(const ReverseVectorIterator &other) const
			{
				return (this->_ptr <= other._ptr);
			};
			value_type &operator*(void)
			{
				return (*this->_ptr);
			};
			value_type *operator->(void)
			{
				return (this->_ptr);
			};
			ReverseVectorIterator operator+(int n) const
			{
				ReverseVectorIterator tmp(*this);
				tmp += n;
				return (tmp);
			};
			ReverseVectorIterator operator-(int n) const
			{
				ReverseVectorIterator tmp(*this);
				tmp -= n;
				return (tmp);
			};
			value_type &operator[](int n) const
			{
				std::cout << "eeeeee" << std::endl;
				return (*(*this - n));
			};
	};
	template <class T>
	class ConstVectorIterator : public VectorIterator<T>
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
			ConstVectorIterator(void)
			{};
			ConstVectorIterator(pointer ptr)
			{
				this->_ptr = ptr;
			};
			ConstVectorIterator(const ConstVectorIterator &other)
			{
				*this = other;
			};
			~ConstVectorIterator(void)
			{};
			ConstVectorIterator &operator=(const ConstVectorIterator &other)
			{
				this->_ptr = other._ptr;
				return (*this);
			};
			const value_type &operator*(void)
			{
				return (*this->_ptr);
			};
			const value_type &operator[](int n) const
			{
				return (*(*this + n));
			}
	};
	template <class T>
	class ConstReverseVectorIterator : public ReverseVectorIterator<T>
	{
		public:
			typedef T value_type;
			typedef T& reference;
			typedef T* pointer;
			ConstReverseVectorIterator(void)
			{};
			ConstReverseVectorIterator(pointer ptr)
			{
				this->_ptr = ptr;
			};
			ConstReverseVectorIterator(const ConstReverseVectorIterator &other)
			{
				*this = other;
			};
			~ConstReverseVectorIterator(void)
			{};
			ConstReverseVectorIterator &operator=(const ConstReverseVectorIterator &other)
			{
				this->_ptr = other._ptr;
				return (*this);
			};
			const value_type &operator*(void)
			{
				return (*this->_ptr);
			};
			const value_type &operator[](int n) const
			{
				return (*(*this - n));
			}
	};
};

#endif