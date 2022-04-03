- Use `#include <bits/stdc++.h>` instead of many includes.
- `++i` is always better than i++, as sometimes i++ creates a copy of the object
- some concepts to learn thoroughly
    - stl
    - two pointer approach
    - window sliding approach
    - recursion
    - binary search
    - heaps
    - trees
- detecting a loop in lined list or duplicate in array ?
    - Modification Method : traverse each linked list and point them to null, if you come again on a node which is already pointing to null, then that is where loop begins, in case array turn the positive integers in negative and if you come accross a negative integer then it is duplicated.\
    - Extra Space Method : use unordered_set to store the addresses of the nodes and in case of aray use maps. 
    - Optimised Method : Use Floyd'd tortoise and hare algorithm to detect cycle. 
- same algo can be applied to `find middle node in LL in O(n)`

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


### Bitwise
- check for ODD EVEN fastly `if(n & 1) ...odd    else ...even`
- use `__builtin_popcount(a)` to find the count of set bits


### Time Complexity from given n-based constraint
Time Complexity from given n-based constraint is based on the fact that `online-judge` can perform 1e8 operations, hence on taking n as the given constraint the outcome should be around 1e8 only
- n ≤ 12, the time complexity can be O(n!).
- n ≤ 25, the time complexity can be O(2n).
- n ≤ 100, the time complexity can be O(n4).
- n ≤ 500, the time complexity can be O(n3).
- n ≤ 1e4, the time complexity can be O(n2).
- n ≤ 1e6, the time complexity can be O(n log n).
- n ≤ 1e8, the time complexity can be O(n).
- n > 1e8, the time complexity can be O(log n) or O(1).

<br>

reff
- https://codeforces.com/blog/entry/64218