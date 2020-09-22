# Stack
## (constructor)
- [x] explicit stack (const container_type& ctnr = container_type());
## empty
- [x] bool empty() const;
## size
- [x] size_type size() const;
## top
- [x] value_type& top()
- [x] const value_type& top() const;
## push
- [x] void push (const value_type& val);
## pop
- [x] void pop();
## relational operators
- [x] template <class T, class Container> bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
- [x] template <class T, class Container> bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
- [x] template <class T, class Container> bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
- [x] template <class T, class Container> bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
- [x] template <class T, class Container> bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
- [x] template <class T, class Container> bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
