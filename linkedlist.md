### Introduction to LinkedList
- when creating a new node always write `node* temp = new node();` and do create a constructor.
- `delete ptr` can be used to delete a pointer block.

### Medium Problems on LinkedList
- __Middle of a LL/ Delete Middle Element__ - [tortoise-hare method](linked_list/middle.cpp)
- __Reverse a LL__ 
- __Detect a loop__ - [tortoise-hare and set method](linked_list/loop.cpp)
- __Find starting point of a loop__ - [tortoise-hare method + some trick](https://takeuforward.org/data-structure/starting-point-of-loop-in-a-linked-list/)
- __Check if LL is palindrome__ - [push to stack and then pop and check again](https://leetcode.com/submissions/detail/809283542/)
- ??? __Interweave Nodes__ - [???](https://www.codingninjas.com/codestudio/problems/interweave-nodes_764142?topList=top-amazon-coding-interview-questions)
- __Sort Linked List__ - [use merge sort concept](linked_list/sort.cpp)
- Sort 0 1 2 
    - just count the number of 0,1,2 and then insert values in LL with the count
    - if do not want to change the original list? or create three nodes and then insert values in them and then merge them



<!-- - detecting a loop in lined list or duplicate in array ?
    - Modification Method : traverse each linked list and point them to null, if you come again on a node which is already pointing to null, then that is where loop begins, in case array turn the positive integers in negative and if you come accross a negative integer then it is duplicated.\
    - Extra Space Method : use unordered_set to store the addresses of the nodes and in case of aray use maps. 
    - Optimisedd Method : Use `Floyd'd tortoise and hare algorithm` to detect cycle. It is kind of Two pointer approach, as one pointer is moving 1 at a time and another is moving 2 at a time.
- same algo can be applied to `find middle node in LL in O(n)`
- [Reverse a Linked List in groups of given size](linked_list/reverse_grp.cpp)
- Clone a ll with next and random pointer -->