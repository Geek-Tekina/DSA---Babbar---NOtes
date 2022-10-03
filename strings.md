### Introduction to Strings
- How strings are stored? (check just below)
    ```txt
    the general idea is that the string class will contain a pointer to a region of memory 
    where the actual contents of the string are stored. Two common implementations are storing 
    - 3 pointers (begin of the allocated region and data, end of data, end of allocated region) 
    - or a pointer (begin of allocated region and data) and two integers (number of characters 
        in the string and number of allocated bytes).
    
    When new data is appended to the string, if it fits the allocated region
    it will just be written and the size/end of data pointer will be updated accordingly.
    If the data does not fit in the region a new buffer will be created and the data copied
    ```
- simplified `atoi`
    ```cpp
    // from babbar video
    ```

### Easy-Medium level Problems
- __Count Words__ - concept of ' ' as delimeter
- __Reverse String word wise__ - concept of ' ' as delimeter
- __Reverse String character wise__
- [__Remove Consecutive Duplicates__](https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118818/offering/1381767) - [code](arrays_cn/remove_dup.cpp)
- [__Check permutation__](https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118818/offering/1381766) - use hashmap for O(n)
- [__Is str1 subequence of str2?__](arrays_cn/is_subsq.cpp) - either map or two pointers 
- [__Anagram Difference__](arrays_cn/anagram_diff.cpp)
- [__Remove Outermost Paranthesis__](https://leetcode.com/problems/remove-outermost-parentheses/) / [__Max. Nesting Depth Paranthesis__](https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/) - concept of brackets into stack
- Sort characters by frequency - use hashmap and then convert to vector of pair and sort in descending order


### Medium-Hard Level Problems
- [__Count and Say__](https://leetcode.com/problems/count-and-say/) 
    - recursive with dp or iterative
    - find the len of consecutive duplicates and then append to the string 
- [__Valid String__](https://leetcode.com/problems/valid-parenthesis-string/submissions/)
    - create `stack<int> open, star` two stacks and store the indices, 
    - now as the `)` pop all the required from open, but if empty star.pop()
    - use the next loop to check if `(` is left or not 
    - in first loop, we are treating star as `(` and in second loop we are treating star as `)`
    - [read code here](https://leetcode.com/submissions/detail/672689384/)
- __Count number of substrings with exactly k distinct characters__
- __Shortest substring with all characters__
- Count Palindromic subsequence 
- [__Transform one string to another__](https://www.geeksforgeeks.org/transform-one-string-to-another-using-minimum-number-of-given-operation/) !!!!


### DP on Strings
- Longest Common Substring
- [__Longest Common Subsequence__](https://leetcode.com/problems/longest-common-subsequence/)
- Read more here - https://leetcode.com/discuss/general-discussion/651719/how-to-solve-dp-string-template-and-4-steps-to-be-followed