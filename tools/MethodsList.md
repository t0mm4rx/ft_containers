# List
## (constructor)
- [ ] explicit list (const allocator_type& alloc = allocator_type());
- [ ] explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
- [ ] template <class InputIterator> list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
- [ ] list (const list& x);
## (destructor)
## operator=
- [ ] list& operator= (const list& x);
## begin
- [ ] iterator begin()
- [ ] const_iterator begin() const;
## end
- [ ] iterator end()
- [ ] const_iterator end() const;
## rbegin
- [ ] reverse_iterator rbegin()
- [ ] const_reverse_iterator rbegin() const;
## rend
- [ ] reverse_iterator rend()
- [ ] const_reverse_iterator rend() const;
## empty
- [ ] bool empty() const;
## size
- [ ] size_type size() const;
## max_size
- [ ] size_type max_size() const;
## front
- [ ] reference front()
- [ ] const_reference front() const;
## back
- [ ] reference back()
- [ ] const_reference back() const;
## assign
- [ ] template <class InputIterator> void assign (InputIterator first, InputIterator last);
- [ ] void assign (size_type n, const value_type& val);
## push_front
- [ ] void push_front (const value_type& val);
## pop_front
- [ ] void pop_front();
## push_back
- [ ] void push_back (const value_type& val);
## pop_back
- [ ] void pop_back();
## insert
- [ ] iterator insert (iterator position, const value_type& val);
- [ ] void insert (iterator position, size_type n, const value_type& val);
- [ ] template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last);
## erase
- [ ] iterator erase (iterator position)
- [ ] iterator erase (iterator first, iterator last);
## swap
- [ ] void swap (list& x);
## resize
- [ ] void resize (size_type n, value_type val = value_type());
## clear
- [ ] void clear();
## splice
- [ ] void splice (iterator position, list& x);
- [ ] void splice (iterator position, list& x, iterator i);
- [ ] void splice (iterator position, list& x, iterator first, iterator last);
## remove
- [ ] void remove (const value_type& val);
## remove_if
- [ ] template <class Predicate> void remove_if (Predicate pred);
## unique
- [ ] void unique();
- [ ] template <class BinaryPredicate> void unique (BinaryPredicate binary_pred);
## merge
- [ ] void merge (list& x);
- [ ] template <class Compare> void merge (list& x, Compare comp);
## sort
- [ ] void sort();
- [ ] template <class Compare> void sort (Compare comp);
## reverse
- [ ] void reverse();
## get_allocator
- [ ] allocator_type get_allocator() const;
## relational operators (list)
## swap (list)
- [ ] template <class T, class Alloc> void swap (list<T,Alloc>& x, list<T,Alloc>& y);
