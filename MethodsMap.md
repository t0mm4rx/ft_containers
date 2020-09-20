# Map
## (constructor)
- [x] explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
- [ ] template <class InputIterator> map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());
- [x] map (const map& x);
## (destructor)
- [x] ~map (void);
## operator=
- [ ] map& operator= (const map& x);
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
- [x] bool empty() const;
## size
- [x] size_type size() const;
## max_size
- [x] size_type max_size() const;
## operator[]
- [ ] mapped_type& operator[] (const key_type& k);
## insert
- [ ] pair<iterator,bool> insert (const value_type& val);
- [ ] iterator insert (iterator position, const value_type& val);
- [ ] template <class InputIterator> void insert (InputIterator first, InputIterator last);
## erase
- [ ] void erase (iterator position);
- [ ] size_type erase (const key_type& k);
- [ ] void erase (iterator first, iterator last);
## swap
- [ ] void swap (map& x);
## clear
- [ ] void clear();
## key_comp
- [x] key_compare key_comp() const;
## value_comp
- [x] value_compare value_comp() const;
## find
- [ ] iterator find (const key_type& k)
- [ ] const_iterator find (const key_type& k) const;
## count
- [ ] size_type count (const key_type& k) const;
## lower_bound
- [ ] iterator lower_bound (const key_type& k)
- [ ] const_iterator lower_bound (const key_type& k) const;
## upper_bound
- [ ] iterator upper_bound (const key_type& k)
- [ ] const_iterator upper_bound (const key_type& k) const;
## equal_range
- [ ] pair<const_iterator,const_iterator> equal_range (const key_type& k) const
- [ ] pair<iterator,iterator> equal_range (const key_type& k);
## get_allocator
- [ ] allocator_type get_allocator() const;
