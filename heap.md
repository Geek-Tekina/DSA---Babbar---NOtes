### Introduction to Heap
- Heap questions are often related to sorting
- It is used to implement priority_queue
- It is a __complete binary tree__ that satisifies the __heap property__
    - a _complete binary tree_ is a binary tree which is completely filled, with the possible exception of the bottom level, which is filled from left to right
    - max heap property is the root is greater than or equal to its children
    - min heap property is the root is less than or equal to its children
- NOTE : Evem though Heap is a tree-based data structure but its not implemented using node and linked list, instead it is implemented using array. And this is what makes it faster than other tree-based data structures.
    - Therefore we wanted heap to be a complete binary tree, so it can be represented using an array and children and parent can be found using simple formula. 
    ```md
    Root is at index 0 in array.
    Left child of i-th node is at (2*i + 1)th index.
    Right child of i-th node is at (2*i + 2)th index.
    Parent of i-th node is at (i-1)/2 index.
    ```


### build_heap()
- __Naive Approach__
    - Heapify a single node takes O(log N) time complexity where N is the total number of Nodes.
    - Therefore, building the entire Heap will take N heapify operations and the total time complexity will be O(N*logN).
    - __Time Complexity Analysis:__ O(n logn)
- __Efficiently__
    - We can build a heap in O(n) time complexity.
    - We can do this by starting from the last non-leaf node and heapify it. __Why last-non-leaf node?__ it is simply because the leaves are already heapified.
    - We can do this for all the non-leaf nodes and we will get a heap in O(n) time complexity. and heapify here just means swap the parent with the max/ min child, and then we have to recursively heapify the child node and further.
    - __Time Complexity Analysis:__ O(n)


### insertion(int x)
- Insertion in a heap is always done from the last position of the heap.
- After this addition, the newly inserted element may violate the heap property, so we have to heapify its parent which will automatically fix the tree.
- __Time Complexity Analysis:__ the new value, at max/ worst case possible => reach up to the root node covering the whole height of the tree and hence the time complexity becomes O(log n).


### deletion()
- Deletion in a heap is always done from the root node but not directly, root index value that is arr[0] is first swapped with the last leaf-node, and then the last leaf-node is deleted.
- Now, the new root value is now compared with its children, and on the basis of type of type it is swapped with either of the children and then that children is further heapified - aka heapify()
- __Time Complexity Analysis:__ at max/ worst case possible => the root value can go back to the leaf posiition covering the whole height of the tree and hence the time complexity becomes O(log n).

### heapify()
- if everything is so straighforward, then what exactly is heapify()?
- heapify is the function that actually performs the swapping operation and then which child to heapify, if required.
- it recursively heapifies the affected sub-tree, from current index to its children.

> NOTE : code can be read here : [heap.cpp](heap/1_basic.cpp)
> Heapify is very important to understand, and it is the core of the heap data structure. It is used to maintain the heap property after insertion and deletion. It is also used to build a heap from an array in O(n) time complexity.