# Stack
## (constructor)
- [ ] explicit stack (const container_type& ctnr = container_type());
## empty
- [ ] bool empty() const;
## size
- [ ] size_type size() const;
## top
- [ ] value_type& top()
- [ ] const value_type& top() const;
## push
- [ ] void push (const value_type& val);
## pop
- [ ] void pop();
## relational operators
- [ ] template <class T, class Container> bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
- [ ] template <class T, class Container> bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
- [ ] template <class T, class Container> bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
- [ ] template <class T, class Container> bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
- [ ] template <class T, class Container> bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
- [ ] template <class T, class Container> bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
