# List
## (constructor)
- [x] explicit list (const allocator_type& alloc = allocator_type());
- [x] explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
- [x] template <class InputIterator> list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
- [x] list (const list& x);
## (destructor)
## operator=
- [x] list& operator= (const list& x);
## begin
- [x] iterator begin()
- [x] const_iterator begin() const;
## end
- [x] iterator end()
- [x] const_iterator end() const;
## rbegin
- [x] reverse_iterator rbegin()
- [x] const_reverse_iterator rbegin() const;
## rend
- [x] reverse_iterator rend()
- [x] const_reverse_iterator rend() const;
## empty
- [x] bool empty() const;
## size
- [x] size_type size() const;
## max_size
- [x] size_type max_size() const;
## front
- [x] reference front()
- [x] const_reference front() const;
## back
- [x] reference back()
- [x] const_reference back() const;
## assign
- [x] template <class InputIterator> void assign (InputIterator first, InputIterator last);
- [x] void assign (size_type n, const value_type& val);
## push_front
- [x] void push_front (const value_type& val);
## pop_front
- [x] void pop_front();
## push_back
- [x] void push_back (const value_type& val);
## pop_back
- [x] void pop_back();
## insert
- [x] iterator insert (iterator position, const value_type& val);
- [x] void insert (iterator position, size_type n, const value_type& val);
- [x] template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last);
## erase
- [x] iterator erase (iterator position)
- [x] iterator erase (iterator first, iterator last);
## swap
- [x] void swap (list& x);
## resize
- [x] void resize (size_type n, value_type val = value_type());
## clear
- [x] void clear();
## splice
- [x] void splice (iterator position, list& x);
- [x] void splice (iterator position, list& x, iterator i);
- [x] void splice (iterator position, list& x, iterator first, iterator last);
## remove
- [x] void remove (const value_type& val);
## remove_if
- [x] template <class Predicate> void remove_if (Predicate pred);
## unique
- [x] void unique();
- [x] template <class BinaryPredicate> void unique (BinaryPredicate binary_pred);
## merge
- [x] void merge (list& x);
- [x] template <class Compare> void merge (list& x, Compare comp);
## sort
- [x] void sort();
- [x] template <class Compare> void sort (Compare comp);
## reverse
- [x] void reverse();
## relational operators (list)
- [x] template <class T, class Alloc> bool operator== (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
- [x] template <class T, class Alloc> bool operator!= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
- [x] template <class T, class Alloc> bool operator<  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
- [x] template <class T, class Alloc> bool operator<= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
- [x] template <class T, class Alloc> bool operator>  (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
- [x] template <class T, class Alloc> bool operator>= (const list<T,Alloc>& lhs, const list<T,Alloc>& rhs);
## swap (list)
- [x] template <class T, class Alloc> void swap (list<T,Alloc>& x, list<T,Alloc>& y);
