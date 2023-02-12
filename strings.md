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
    char val = '9';
    cout << val - '0';
    // it will subtract the ascii code of 0 from val and convert to int
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
- [__Count number of substrings with exactly k distinct characters](https://www.geeksforgeeks.org/count-number-of-substrings-with-exactly-k-distinct-characters/)__ - think of an n*n approach, where each char is treated as starting point and then from that point we find the possible substrings with k distinct chars 
- __Shortest substring with all characters__ 
    - use map and two pointer concept
    - if a character is not present in map, then add it and move j
    - else if present, then use the map to find the index, and move the i to that index+1, while also removing the characters from map
    - Time Complexity ??


### Hard level
- Prefix Function
    - Prefix function generates an array of size n. The value of the array at index i is the length of the longest proper prefix of the substring s[0...i] which is also a suffix of this substring only.
    - [prefix explanation and code](.assets/prefix.jpeg)
- KMP 
- Rabin Karp


### DP on Strings
- __Longest Common Subsequence__
    - In LCS, if i and j values are equal then, 1+lcs(i-1, j-1)
    - else to consider all the cases, take out max(lcs(i-1, j), lcs(i, j-1))
    - Time Complexity - O(mn)
    - __Print LCS__ - from `dp[m][n] to dp[0][0]`, if `str1[m] == str2[n] ? res.insert(str1[m], 0) : either top or left`
- __Longest Common Substring__
    - In LC-Substring, if i and j values are equal then ofc 1+lcs(i-1, j-1) but then also check if its the max value then store in answer `res = max(res, dp[i][j])`
    - else if not equal then `dp[i][j] as 0`
- [Code is here](dp_av/6_lcs.cpp)
- __[Shortest common supersequence](dp_av/7_sc_superseq.cpp)__
    - generate lcs dp-table, then using the print lcs method, also print the chars while going up/left 
- __Longest Palindromic Subseq.__ - lcs of str and reverse(str)
- __Min. deletion and insertion to convert a to b__ - [code](dp_av/8_min_ins_del.cpp)
- __Subsequence pattern matching__ - check if `lcs(pattern, str) == pattern.size()`
- Read more here - https://leetcode.com/discuss/general-discussion/651719/how-to-solve-dp-string-template-and-4-steps-to-be-followed