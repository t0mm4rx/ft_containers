# Queue
## (constructor)
- [ ] explicit queue (const container_type& ctnr = container_type());
## empty
- [ ] bool empty() const;
## size
- [ ] size_type size() const;
## front
- [ ] value_type& front()
- [ ] const value_type& front() const;
## back
- [ ] value_type& back()
- [ ] const value_type& back() const;
## push
- [ ] void push (const value_type& val);
## pop
- [ ] void pop();
## relational operators
- [ ] template <class T, class Container> bool operator== (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
- [ ] template <class T, class Container> bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
- [ ] template <class T, class Container> bool operator< (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
- [ ] template <class T, class Container> bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
- [ ] template <class T, class Container> bool operator> (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
- [ ] template <class T, class Container> bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
