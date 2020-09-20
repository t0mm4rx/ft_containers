#ifndef MAP_HPP
# define MAP_HPP
# include <memory>
# include <functional>
# include <limits>

namespace ft
{
	template <class Key, class T, class Compare=std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T> > >
	class Map
	{
		public:
			typedef Key key_type;
			typedef T mapped_type;
			typedef std::pair<const key_type, mapped_type> value_type;
			typedef Compare key_compare;
			typedef Alloc allocator_type;
			typedef T& reference;
			typedef const T& const_reference;
			typedef T* pointer;
			typedef const T* const_pointer;
			typedef unsigned long size_type;
			typedef BNode<key_type, mapped_type>* node;
			class value_compare
			{
				friend class map;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {};
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					};
			};
		private:
			allocator_type _allocator;
			key_compare _comp;
			node _root;
			size_type _length;
			node _new_node(key_type key, mapped_type value, bool root = false)
			{
				node el = new BNode<key_type, mapped_type>();
				el->key = key;
				el->value = value;
				el->right = 0;
				el->left = 0;
				el->root = root;
				return (el);
			};
			void _init_tree(void)
			{
				_root = _new_node(key_type(), mapped_type(), true);
				_length = 0;
			};
			void _free_tree(node n)
			{
				if (n->right)
					_free_tree(n->right);
				if (n->left)
					_free_tree(n->left);
				delete n;
			};
		public:
			explicit Map(const key_compare &comp = key_compare(), const allocator_type alloc = allocator_type())
			: _allocator(alloc), _comp(comp)
			{
				_init_tree();
			};
			template <class InputIterator>
			Map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type alloc = allocator_type())
			: _allocator(alloc), _comp(comp)
			{
				(void)first;
				(void)last;
				_init_tree();
			};
			Map(const Map &other)
			{
				*this = other;
			};
			~Map(void)
			{
				_free_tree(_root);	
			};
			Map &operator=(const Map &other)
			{
				(void)other;
				return (*this);
			};
			// iterator begin(void)
			// {};
			// const_iterator begin(void) const
			// {};
			// iterator end(void)
			// {};
			// const_iterator end(void) const
			// {};
			// reverse_iterator rbegin(void)
			// {};
			// const_reverse_iterator rbegin(void) const
			// {};
			// reverse_iterator rend(void)
			// {};
			// const_reverse_iterator rend(void) const
			// {};
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
				return (std::numeric_limits<size_type>::max() / sizeof(node));
			};
			// mapped_type &operator[](const key_type& k)
			// {

			// };
			// std::pair<iterator, bool> insert(const value_type &value)
			// {};
			// iterator insert(const value_type &value)
			// {};
			// template <class InputIterator>
			// void insert(InputIterator first, InputIterator last)
			// {};
			// void erase(iterator position)
			// {};
			// size_type erase(const key_type &value)
			// {};
			// void erase(iterator first, iterator last)
			// {};
			// void swap(Map &x)
			// {};
			// void clear(void)
			// {};
			key_compare key_comp(void) const
			{
				return (_comp);
			};
			value_compare value_comp(void) const
			{
				return (this->value_compare);
			};
			// iterator find(const key_type &value)
			// {};
			// const_iterator find(const key_type &value) const
			// {};
			// size_type count(const key_type &value) const
			// {};
			// iterator lower_bound(const key_type &value)
			// {};
	};
};

#endif