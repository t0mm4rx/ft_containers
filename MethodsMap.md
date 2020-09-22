# Map
## (constructor)
- [x] explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
- [x] template <class InputIterator> map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
- [x] map (const map& x);
## (destructor)
- [x] ~map (void);
## operator=
- [x] map& operator= (const map& x);
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
## operator[]
- [x] mapped_type& operator[] (const key_type& k);
## insert
- [x] pair<iterator,bool> insert (const value_type& val);
- [x] iterator insert (iterator position, const value_type& val);
- [x] template <class InputIterator> void insert (InputIterator first, InputIterator last);
## erase
- [x] void erase (iterator position);
- [x] size_type erase (const key_type& k);
- [x] void erase (iterator first, iterator last);
## swap
- [x] void swap (map& x);
## clear
- [x] void clear();
## key_comp
- [x] key_compare key_comp() const;
## value_comp
- [x] value_compare value_comp() const;
## find
- [x] iterator find (const key_type& k)
- [ ] const_iterator find (const key_type& k) const;
## count
- [x] size_type count (const key_type& k) const;
## lower_bound
- [x] iterator lower_bound (const key_type& k)
- [x] const_iterator lower_bound (const key_type& k) const;
## upper_bound
- [x] iterator upper_bound (const key_type& k)
- [x] const_iterator upper_bound (const key_type& k) const;
## equal_range
- [x] pair<const_iterator,const_iterator> equal_range (const key_type& k) const
- [x] pair<iterator,iterator> equal_range (const key_type& k);
