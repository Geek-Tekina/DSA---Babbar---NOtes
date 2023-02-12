# README.MD

- [ ] Interview Questions
    - [Time-complexity](https://www.geeksforgeeks.org/practice-questions-time-complexity-analysis/)
        - [Sorting algos](https://www.geeksforgeeks.org/time-complexities-of-all-sorting-algorithms/)
    - [C++](https://www.interviewbit.com/cpp-interview-questions/)
    - [Pointers](pointers.cpp)
    - [STL](#stl)
- [x] Recursion - refer copy
- [x] [Trees (Binary Trees and BST)](trees.md)
- [x] [Graphs / Backtracking-Tips](graphs.md)
- [ ] [Heap](heap.md)
- [x] [Linked List](linkedlist.md)
- [x] [Strings](strings.md)
- [x] [Binary Search](binary_search.md)
- [ ] [Array](arrays.md)
- [x] [Stacks and Queues](stacks_queues.md)
- [x] Dynamic Programming (_refer copy_)
- [ ] [Greedy Algos](greedy.md)

<hr>

## STL
The Standard Template Library (STL) is a set of C++ template classes to provide common programming data structures and functions such as lists, stacks, arrays, etc. It is a library of **container** classes, algorithms, and **iterators**. It is a generalized library and so, its components are parameterized.

### Containers (types)
- Vectors [[Cheatsheet](.assets/vectors_cheatsheet.pdf)]
- Maps [[GFG](https://www.geeksforgeeks.org/map-vs-unordered_map-c/)]
- Sets [[GFG](https://www.geeksforgeeks.org/set-vs-unordered_set-c-stl/)]
- [Maps & Sets Cheatsheet](.assets/maps_sets_cheatsheet.pdf)

### Iterators
Iterators are used to point at the memory addresses of STL containers. They are primarily used in sequence of numbers, characters etc. They reduce the complexity and execution time of program.
Operations of iterators :-
- begin() : to return the beginning position of the container.
- end() : to return the after end position of the container.
- more at https://www.geeksforgeeks.org/iterators-c-stl/

### Vectors
- append a vector with a vector `res.insert(res.end(), mat[i].begin(), mat[i].end());`
- get unique elements from a vector
    ```cpp
        vector<int> v = { 1, 2, 3, 3, 3, 10, 1, 2, 3, 7, 7, 8 };
        sort(v.begin(), v.end());
        // #include <algorithm>
        v.resize(std::distance(v.begin(), unique(v.begin(), v.end())));
        for (auto ip: v) {
            cout << ip << " ";
        }
        cout << endl << v.size();            // new size
    ```

## Misc Points
- Use `#include <bits/stdc++.h>` instead of many includes.
- `++i` is always better than i++, as sometimes i++ creates a copy of the object
- what is `modulo 10e9 + 7`
- check for ODD EVEN fastly `if(n & 1) ...odd    else ...even`, why? bec each number, EACH is even if last binary digit is 0 or else odd if its 1.
- use `__builtin_popcount(a)` to find the count of set bits
- Time Complexity from given n-based constraint
    - n ≤ 12, the time complexity can be O(n!).
    - n ≤ 25, the time complexity can be O(2n).
    - n ≤ 100, the time complexity can be O(n4).
    - n ≤ 500, the time complexity can be O(n3).
    - n ≤ 1e4, the time complexity can be O(n2).
    - n ≤ 1e6, the time complexity can be O(n log n).
    - n ≤ 1e8, the time complexity can be O(n).
    - n > 1e8, the time complexity can be O(log n) or O(1).