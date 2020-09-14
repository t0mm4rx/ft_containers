# ft_containers

## Researches

- http://www.cplusplus.com/reference/stl/
- https://thispointer.com/difference-between-vector-and-list-in-c/
- https://www.youtube.com/watch?v=qvZGUFHWChY

## How does containers work?

### list

List works with a double linked-list.

### vector

Vector work with a dynamic array: new T[size].

### map

Map is an associative array (key => value). It cannot have two pairs with the same key.
We can use std::pair to store a pair keu/value.
It's implemented using a red-black binary tree.

## stack

Stack is a LIFO container. It can be built with other containers, such as list.
We'll use a private property that will be a container (list by default), but it can be specified during instanciation.

## queue

Queue is a FIFO container. As stack, we'll use an other container specified during instanciation to build it.

## ToDo

### list

### vector

- [ ] constructor
- [ ] destructor
- [ ] operator=
- [ ] begin
- [ ] end
- [ ] rbegin
- [ ] rend
- [ ] size
- [ ] max_size
- [ ] resize
- [ ] capacity
- [ ] empty
- [ ] reserve
- [ ] operator[]
- [ ] at
- [ ] front
- [ ] back
- [ ] assign
- [ ] push_back
- [ ] pop_back
- [ ] insert
- [ ] erase
- [ ] swap
- [ ] clear
- [ ] operator!=
- [ ] operator==
- [ ] operator<=
- [ ] operator<
- [ ] operator>=
- [ ] operator>