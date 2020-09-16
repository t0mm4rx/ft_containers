# Vector
## (constructor)
- [ ] explicit vector (const allocator_type& alloc = allocator_type());
- [ ] explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
- [ ] template <class InputIterator> vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
- [ ] vector (const vector& x);
## (destructor)
## operator=
- [ ] vector& operator= (const vector& x);
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
## size
- [ ] size_type size() const;
## max_size
- [ ] size_type max_size() const;
## resize
- [ ] void resize (size_type n, value_type val = value_type());
## capacity
- [ ] size_type capacity() const;
## empty
- [ ] bool empty() const;
## reserve
- [ ] void reserve (size_type n);
## operator[]
- [ ] reference operator[] (size_type n)
- [ ] const_reference operator[] (size_type n) const;
## at
- [ ] reference at (size_type n)
- [ ] const_reference at (size_type n) const;
## front
- [ ] reference front()
- [ ] const_reference front() const;
## back
- [ ] reference back()
- [ ] const_reference back() const;
## assign
- [ ] template <class InputIterator> void assign (InputIterator first, InputIterator last);
- [ ] void assign (size_type n, const value_type& val);
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
## clear
- [ ] void clear();
## get_allocator
- [ ] allocator_type get_allocator() const;
## relational operators
- [ ] template <class T, class Alloc> bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
- [ ] template <class T, class Alloc> bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
- [ ] template <class T, class Alloc> bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
- [ ] template <class T, class Alloc> bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
- [ ] template <class T, class Alloc> bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
- [ ] template <class T, class Alloc> bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs);
## swap
- [ ] template <class T, class Alloc> void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
## vector<bool>
- [ ] template < class T, class Alloc = allocator<T> > class vector
- [ ] // generic template template <class Alloc> class vector<bool,Alloc>
- [ ] // bool specialization
