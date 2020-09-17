# Vector
## (constructor)
- [x] explicit vector (const allocator_type& alloc = allocator_type());
- [x] explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
- [x] template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
- [x] vector (const vector& x);
## (destructor)
## operator=
- [x] vector& operator= (const vector& x);
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
## size
- [x] size_type size() const;
## max_size
- [x] size_type max_size() const;
## resize
- [x] void resize (size_type n, value_type val = value_type());
## capacity
- [x] size_type capacity() const;
## empty
- [x] bool empty() const;
## reserve
- [x] void reserve (size_type n);
## operator[]
- [x] reference operator[] (size_type n)
- [x] const_reference operator[] (size_type n) const;
## at
- [x] reference at (size_type n)
- [x] const_reference at (size_type n) const;
## front
- [x] reference front()
- [x] const_reference front() const;
## back
- [x] reference back()
- [x] const_reference back() const;
## assign
- [x] template <class InputIterator> void assign (InputIterator first, InputIterator last);
- [x] void assign (size_type n, const value_type& val);
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
## clear
- [x] void clear();
## swap
- [x] void swap(Vector &x);
## relational operators
- [x] template <class T, class Alloc> bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
- [x] template <class T, class Alloc> bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
- [x] template <class T, class Alloc> bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
- [x] template <class T, class Alloc> bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
- [x] template <class T, class Alloc> bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
- [x] template <class T, class Alloc> bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
## swap
- [x] template <class T, class Alloc> void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
