# ft_containers
## Researches
- http://www.cplusplus.com/reference/stl/
- https://thispointer.com/difference-between-vector-and-list-in-c/
- https://www.youtube.com/watch?v=qvZGUFHWChY
- https://www.geeksforgeeks.org/difference-between-stack-and-queue-data-structures/
## How does containers work?
### list
List works with a double linked-list.
### vector
Vector work with a dynamic array: new T[size].
_container is the array containing objects.
_container_size is the size of _container in memory.
_container_length is the number of elements in the array.
### map
Map is an associative array (key => value). It cannot have two pairs with the same key.
We can use std::pair to store a pair key/value.
It's implemented using a binary tree.
### stack
Stack is a LIFO container. It can be built with other containers, such as list.
We'll use a private property that will be a container (list by default), but it can be specified during instanciation.
### queue
Queue is a FIFO container. As stack, we'll use an other container specified during instanciation to build it.
## ToDo
### list
- [ ] constructor
- [ ] destructor
- [ ] operator=
- [ ] begin
- [ ] end
- [ ] rbegin
- [ ] rend
- [ ] empty
- [ ] size
- [ ] max_size
- [ ] front
- [ ] back
- [ ] assign
- [ ] push_front
- [ ] pop_front
- [ ] push_back
- [ ] pop_back
- [ ] insert
- [ ] erase
- [ ] swap
- [ ] resize
- [ ] clear
- [ ] splice
- [ ] remove
- [ ] remove_if
- [ ] unique
- [ ] merge
- [ ] sort
- [ ] reverse
- [ ] operator!=
- [ ] operator==
- [ ] operator<=
- [ ] operator<
- [ ] operator>=
- [ ] operator>
### vector
- [x] empty constructor
- [x] fill constructor
- [x] range constructor
- [x] copy constructor
- [ ] destructor
- [ ] operator=
- [x] begin
- [x] end
- [ ] begin const
- [ ] end const
- [ ] rbegin
- [ ] rend
- [ ] rbegin const
- [ ] rend const
- [x] size
- [x] max_size
- [ ] resize
- [x] capacity
- [x] empty
- [x] reserve
- [x] operator[]
- [ ] at
- [ ] at const
- [ ] front
- [ ] back
- [ ] range assign
- [ ] fill assign
- [x] push_back
- [ ] pop_back
- [x] single element insert
- [x] fill insert
- [x] range insert
- [ ] single element erase
- [ ] range erase
- [ ] swap
- [ ] clear
- [ ] operator!=
- [ ] operator==
- [ ] operator<=
- [ ] operator<
- [ ] operator>=
- [ ] operator>
### map
- [ ] constructor
- [ ] destructor
- [ ] operator=
- [ ] begin
- [ ] end
- [ ] rbegin
- [ ] rend
- [ ] empty
- [ ] size
- [ ] max_size
- [ ] operator[]
- [ ] insert
- [ ] erase
- [ ] swap
- [ ] clear
- [ ] key_comp
- [ ] value_comp
- [ ] find
- [ ] count
- [ ] lower_bound
- [ ] upper_bound
- [ ] equal_range
### stack
- [ ] empty
- [ ] size
- [ ] top
- [ ] push
- [ ] pop
- [ ] operator!=
- [ ] operator==
- [ ] operator<=
- [ ] operator<
- [ ] operator>=
- [ ] operator>
### queue
- [ ] empty
- [ ] size
- [ ] front
- [ ] back
- [ ] push
- [ ] pop
- [ ] operator!=
- [ ] operator==
- [ ] operator<=
- [ ] operator<
- [ ] operator>=
- [ ] operator>