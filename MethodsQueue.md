# Queue
## (constructor)
- [x] explicit queue (const container_type& ctnr = container_type());
## empty
- [x] bool empty() const;
## size
- [x] size_type size() const;
## front
- [x] value_type& front()
- [x] const value_type& front() const;
## back
- [x] value_type& back()
- [x] const value_type& back() const;
## push
- [x] void push (const value_type& val);
## pop
- [x] void pop();
## relational operators
- [ ] template <class T, class Container> bool operator== (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
- [ ] template <class T, class Container> bool operator!= (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
- [ ] template <class T, class Container> bool operator< (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
- [ ] template <class T, class Container> bool operator<= (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
- [ ] template <class T, class Container> bool operator> (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
- [ ] template <class T, class Container> bool operator>= (const queue<T,Container>& lhs, const queue<T,Container>& rhs);
