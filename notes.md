- Use `#include <bits/stdc++.h>` instead of many includes.
- `++i` is always better than i++, as sometimes i++ creates a copy of the object
- some concepts to learn thoroughly
    - heaps
    - binary search
    - recursion
    - stl
    - two pointer approach
    - window sliding approach
- detecting a loop in lined list or duplicate in array ?
    - Modification Method : traverse each linked list and point them to null, if you come again on a node which is already pointing to null, then that is where loop begins, in case array turn the positive integers in negative and if you come accross a negative integer then it is duplicated.\
    - Extra Space Method : use unordered_set to store the addresses of the nodes and in case of aray use maps. 
    - Optimisedd Method : Use Floyd'd tortoise and hare algorithm to detect cycle. 
- same algo can be applied to `find middle node in LL in O(n)`

reff
- https://codeforces.com/blog/entry/64218