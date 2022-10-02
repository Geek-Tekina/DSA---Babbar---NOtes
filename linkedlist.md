### Introduction to LinkedList
- when creating a new node always write `node* temp = new node();` and do create a constructor.
- `delete node` can be used to delete a pointer block.

### Medium Problems on LinkedList
- __Middle of a LL/ Delete Middle Element__ - [tortoise-hare method](linked_list/middle.cpp)
- __Reverse a LL__ 
- __Detect a loop__ - [MUST READ : tortoise-hare and set method](linked_list/loop.cpp)
- __Find starting point of a loop__ 
    - use set for extra space method
    - [tortoise-hare method + some trick for no space](https://takeuforward.org/data-structure/starting-point-of-loop-in-a-linked-list/)
- __Check if LL is palindrome__ - [push to stack and then pop and check again](https://leetcode.com/submissions/detail/809283542/)
- ??? __Interweave Nodes__ - [???](https://www.codingninjas.com/codestudio/problems/interweave-nodes_764142?topList=top-amazon-coding-interview-questions)
- __Sort Linked List__ - [use merge sort concept](linked_list/sort.cpp)
- Sort 0 1 2 
    - just count the number of 0,1,2 and then insert values in LL with the count
    - if do not want to change the original list? or create three nodes and then insert values in them and then merge them
- __Rotate linked list__ - for o(n) get `*front and *rear` and then simply take node from front and add to rear

### Hard Level Questions
- __[Reverse a Linked List in groups of given size](linked_list/reverse_grp.cpp)__
    - recursively reverse the groups and then connect the nodes
- __Flatten the Linked List__
    - use bfs concept with vector of nodes to store disconnected bottom nodes 
    - initialise it with `{ head }`
    - recursively, traverse each element in this vector and add bottom to this vector
- __[Copy List with Random pointers](https://leetcode.com/problems/copy-list-with-random-pointer/submissions/)__
    - add a copy node after each node
    - point curr->next->random to curr->random->next
    - for curr = head->next ; curr->next != NULL  
    - curr->next = curr->next->next and curr->next