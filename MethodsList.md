# List
## (constructor)
- [x] explicit list (const allocator_type& alloc = allocator_type());
- [x] explicit list (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
- [x] template <class InputIterator> list (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
- [x] list (const list& x);
## (destructor)
## operator=
- [ ] list& operator= (const list& x);
## begin
- [x] iterator begin()
- [ ] const_iterator begin() const;
## end
- [x] iterator end()
- [ ] const_iterator end() const;
## rbegin
- [ ] reverse_iterator rbegin()
- [ ] const_reverse_iterator rbegin() const;
## rend
- [ ] reverse_iterator rend()
- [ ] const_reverse_iterator rend() const;
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
- [ ] iterator insert (iterator position, const value_type& val);
- [ ] void insert (iterator position, size_type n, const value_type& val);
- [ ] template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last);
## erase
- [ ] iterator erase (iterator position)
- [ ] iterator erase (iterator first, iterator last);
## swap
- [x] void swap (list& x);
## resize
- [ ] void resize (size_type n, value_type val = value_type());
## clear
- [x] void clear();
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
- [x] void sort();
- [x] template <class Compare> void sort (Compare comp);
## reverse
- [x] void reverse();
## relational operators (list)
## swap (list)
- [x] template <class T, class Alloc> void swap (list<T,Alloc>& x, list<T,Alloc>& y);
