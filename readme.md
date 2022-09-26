# README.MD

- [ ] [Pointers](pointers.cpp)
- [ ] [STL](#stl)
- [ ] [Array & Strings](#arrays-and-strings)
- [ ] [Linked List](#linked-list)
- [ ] [Recursion & Backtracking](#recursion--backtracking)
- [ ] [Greedy Algos](greedy.md)
- [ ] [Binary Search](#binary-search)
- [ ] [Stacks and Queues](#stacks-and-queues)
- [ ] [Trees (Binary Trees and BST)](trees.md)
- [ ] [Graphs](graphs.md)
- [ ] DP - refer copy

<hr>

__For interview__
- [Shell](./shell.md)
- Regex
- [DBMS/ SQL](.assets/cs_fundamentals/dbms_tutorial.pdf)
- [OS](.assets/cs_fundamentals/os.pdf)
- [OOPS/ Programming theoretical](.assets/cs_fundamentals/oops.pdf)
- [Flutter](https://docs.google.com/document/d/1n8t_xwEaW0EtSA8E9NW6Ey3bU2W08_tJYxHuW3952ao/edit?usp=sharing)
- Node JS
<hr>

### STL

The Standard Template Library (STL) is a set of C++ template classes to provide common programming data structures and functions such as lists, stacks, arrays, etc. It is a library of **container** classes, algorithms, and **iterators**. It is a generalized library and so, its components are parameterized.

**Containers (types) :**
- Vectors [[Cheatsheet](.assets/vectors_cheatsheet.pdf)]
- Maps [[GFG](https://www.geeksforgeeks.org/map-vs-unordered_map-c/)]
- Sets [[GFG](https://www.geeksforgeeks.org/set-vs-unordered_set-c-stl/)]
- [Maps & Sets Cheatsheet](.assets/maps_sets_cheatsheet.pdf)

**Iterators :**
Iterators are used to point at the memory addresses of STL containers. They are primarily used in sequence of numbers, characters etc. They reduce the complexity and execution time of program.
Operations of iterators :-
- begin() : to return the beginning position of the container.
- end() : to return the after end position of the container.
- more at https://www.geeksforgeeks.org/iterators-c-stl/

<hr>

### Arrays and Strings
<!-- Do it from [Love Babbar Sheet](https://docs.google.com/spreadsheets/d/1sDSzwTi8mNp7IN8dL1rhZ0D1tCQQhMaAGeLptTg7tQU/edit?usp=sharing) -->

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
- stringsBasics of 
    - How strings are stored? (check just below)
    - Practice problems from [coding ninja](https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118818/offering/1381763)
    - [Check permutation](https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118818/offering/1381766) ; use hashmap for O(n)
    - For questions with split on the basis of a delimiter concept,
    - 450 sheet questions
    ```cpp
        for(int i=0 ; i<input.size() ; ++i){
            word += input[i];
            if(input[i] == ' '){
                result.insert(0, word);
                word = "";
            }
        }
    ```

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
        - Easy, [Is subequence](arrays_cn/is_subsq.cpp)
        - Easy, Remove Duplicates ; [soln](arrays_cn/remove_dup.cpp)
        - [Valid String](https://leetcode.com/problems/valid-parenthesis-string/submissions/) ; create open and star stacks and store the indices, now as the `)` pops all the required `( or  *`, use the next loop to check if `(` is left or not 
        - Shortest substring with all characters !!!!
        - Hard, [Transform one string to another](https://www.geeksforgeeks.org/transform-one-string-to-another-using-minimum-number-of-given-operation/) !!!!
    - [Sliding Window Algorithm](sliding_window.md)
    - [Kadane's Algo](sliding_window.md)

- Mixed Problems
    - [Find 2nd largest number](https://www.geeksforgeeks.org/find-second-largest-element-array/)
    - Inpace rotate array by 90 degrees : apply transpose (i,j) to (j,i) and then reverse the columns    
    - [Anagram Difference](arrays_cn/anagram_diff.cpp)

<br>

**REFF** : [Parikh jain list](https://dynalist.io/d/f8y9_YRZW6Kt5-hLfqkW3kDS) 

<hr>


### Linked List

- [Strivers Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)
- when creating a new node always write `node* temp = new node();` and do create a constructor.
- `delete ptr` can be used to delete a pointer block.
- detecting a loop in lined list or duplicate in array ?
    - Modification Method : traverse each linked list and point them to null, if you come again on a node which is already pointing to null, then that is where loop begins, in case array turn the positive integers in negative and if you come accross a negative integer then it is duplicated.\
    - Extra Space Method : use unordered_set to store the addresses of the nodes and in case of aray use maps. 
    - Optimisedd Method : Use `Floyd'd tortoise and hare algorithm` to detect cycle. It is kind of Two pointer approach, as one pointer is moving 1 at a time and another is moving 2 at a time.
- same algo can be applied to `find middle node in LL in O(n)`
- [Reverse a Linked List in groups of given size](linked_list/reverse_grp.cpp)
- Clone a ll with next and random pointer

<hr>

### Recursion & Backtracking

Recursion
- [Youtube by Aditya Verma](https://www.youtube.com/watch?v=kHi1DUhp9kM&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY)
- from [Strivers Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)
- > Make input smaller in some logical manner or If can, apply IBH
- with problems to **add recursive outputs in an array** and then return, what you can do is create a global vector and then add the outputs there (e.g. check below [1]) or you can pass by reference in the argument `solve(vector<int> &ds,)`
```cpp
    // [1] IMP
    vector<int> res;
    void solve(vector<int> inp, int op){
        if(inp.size()==0)   res.push_back(op);
        else {
            int temp = inp.back();
            inp.pop_back();
            solve(inp, op);
            solve(inp, op+temp);
        }
    }    

    vector<int> subsetSums(vector<int> arr, int N)
    {
        solve(arr,0);
        return res;
    }

```
- >n-decision approach and binary approach.
```
for problems like find **unique** subsets/ combinations to add up to a target.
use for loop to check every possible decision. and use "n" index to pass instead of trimming the input.
This is called n-decision approach.
```
<br>

Backtracking
- for theory intro : https://www.youtube.com/watch?v=DKCbsiDBN6c
- Strivers sheet and then Love Babbar
- `rat trap in a maze` is a famous concept problem 

<hr>

### Binary Search
- Instead of `mid = start+end/2` use `mid = start + (end-start)/2`, to remove integer overflow
- In cases you dont know the high limit or the array is **infinite**, use Binary Search in reverse manner that is keep increasing the `high to 2*high and start to high` until condition is met.
- In hard questions, the basic goal should be
    - see and observe a monotonic f(n), and doing this might take time
    - this monotonic series will have a computation function, f(n) and initially dont mind it,
    - find a low and a high, generally it is based on the result domain of the question and then result is cross verified if it can make the question condition true.
    - f(n) is actually responsible for checking if the current value is valid or not.

<hr>

### Stacks and Queues
- Implementation Of Stacks 
    - Using Array
    - Using Linked List
    - Revese A Stack Using Another Stack ; pop from s1 and push to s2
- Implementation Of Queues
    - Using Array
    - Using Linked List
    - [Reverse A Queue](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380946) ; use a stack to reverse and then store back in the queue
- Implementation Important Questions
    - [Min Stack](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380937) ; !!! [Soln](https://takeuforward.org/data-structure/implement-min-stack-o2n-and-on-space-complexity/)
    - [Stack Using 2 Queues](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380940) ; [Soln](https://www.youtube.com/watch?v=jDZQKzEtbYQ)
    - [Queue Using 2 Stacks](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380939) ; 
    - [Two Stacks](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380938) ; divides array in two stacks one from L one from R, R is given too.
    - [Implement A Deque](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118796/offering/1381380)
- Easy Level
    - [Sort A Stack](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380948)
    - [Delete Middle Element From Stack](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380949) ; pop and store in a stack and then push back
    - [Valid Paranthesis](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380944)
    - [Reverse First K Elements Of Queue](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380947) ; move first k elements to a stack and then move back to a queue (Reverse a queue concept) and then just push rest of the elements from q1 to q2.
-  Medium Level
    - [Evaluation Of Postfix Experession](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380942)
    - [Next Greater Element](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380943) ; (--i, asc) 
    - Previous Greater Element ; (++i, asc)
    - [Previous Small/ Nearest supporter](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380952) ; (++i, desc)
    - Next Small Element ; (--i, dsc)
    - Index based prev/next greater/smaller questions e.g. [Stock Span](https://leetcode.com/problems/online-stock-span/), [Area of rect](https://takeuforward.org/data-structure/area-of-largest-rectangle-in-histogram/)
    - Maximum Area of Histogram
- Hard Level
    - [LRU Cache Implementation](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380941) ; [Concept](https://www.youtube.com/watch?v=xDEuM5qa0zg&t=774s) + [code](https://www.youtube.com/watch?v=Xc4sICC8m4M&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&t=0s)
    - [Execution Time](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380951) !!!!
    - [Maximum of minimum for every window size](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380950)


<hr>

### Trie
- Unacademy lectures 
- Strivers questions