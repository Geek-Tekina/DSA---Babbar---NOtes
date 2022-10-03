
### Arrays
- Notes
    - `int max = 1e6; int a[max];` is valid and is the maximum storage for array with 10^6 elemnts.
    - `int a[n]` is possible
    - `sort(arr, arr+n)` can be used to sort using `<algorithm>` header file
- Basics of array
    - [Rotate array](https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118787/offering/1381279) ; [3 different ways](https://betterprogramming.pub/3-ways-to-rotate-an-array-2a45b39f7bec) ; [code in o(n) time and o(1) space](arrays/rotate_array.cpp)
    - [kth largest and smallest element](https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118787/offering/1381281?leftPanelTab=0) !!! ; use QuickSelect to solve in O(n)
- Basics of 2D array
    - How are they stored - row major and column major
    - Wave traversal (using one nested and one insert operation to avoid TLE)
    - Spiral traversal 
- Sorting
    ```cpp
    #include<algorithm>
    sort(vec.begin(), vec.end(), comp);     // can use a static bool comp(Obj a, Obj b){...}
                                            // for asc, it should return true if a is smaller
    sort(arr, arr+n);
    stable_sort(arr, arr+n);                // for stable sort
    ```
    - [Sort array in wave form](https://www.geeksforgeeks.org/sort-array-wave-form-2/#)
    - [Sort array acc to the count of set bits](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118822/offering/1382140?leftPanelTab=1) ; using `__builtin_popcount(a)` to count set bits
    - [Relative sorting](https://leetcode.com/problems/relative-sort-array/) ; [Soln](https://www.youtube.com/watch?v=bNuMPAuQN4g)
    - Med/Hard, [Min number of swaps](https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/)
    - Practice problems from [coding ninja](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118822/offering/1382158)
- Algorithms 
    - [Dutch National Flag](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381862) ; If 3 different elements are given to sort, then DNF can be used to sort in just `O(n)` time
    - [Two Pointer Approach](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118509/offering/1376553)
        - [Length of the max  mountain subarray](https://leetcode.com/problems/longest-mountain-in-array/) ; [for i, run 2 nested j loops and then i = j](https://www.youtube.com/watch?v=rh2Bkul2zzQ)
        - triplets - withEqualZero/ sumEqualToThird/ equalToGivenSum ; [do check out the solution bec shrinking pointers is important](arrays_cn/3sum.cpp)
        - Container with most water ; keep the pointers at both end and shrink just on the basis of small value 
    - [Sliding Window Algorithm](sliding_window.md)
    - [Kadane's Algo](sliding_window.md)
- Mixed Problems
    - [Find 2nd largest number](https://www.geeksforgeeks.org/find-second-largest-element-array/)
    - Inpace rotate array by 90 degrees : apply transpose (i,j) to (j,i) and then reverse the columns    

