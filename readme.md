# README.MD

1. [STL](#stl)
2. [Array](#arrays)
3. [Linked List](#linked-list)
4. [Recursion & Backtracking](#recursion--backtracking)
5. [Greedy Algos](#greedy-algos)
6. [Binary Search](#binary-search)
7. [Stacks and Queues](#stacks-and-queues)

<hr>

## STL

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

## Arrays
Do it from [Love Babbar Sheet](https://docs.google.com/spreadsheets/d/1sDSzwTi8mNp7IN8dL1rhZ0D1tCQQhMaAGeLptTg7tQU/edit?usp=sharing)

<hr>

## Linked List

- [Strivers Sheet](https://takeuforward.org/interviews/strivers-sde-sheet-top-coding-interview-problems/)
- detecting a loop in lined list or duplicate in array ?
    - Modification Method : traverse each linked list and point them to null, if you come again on a node which is already pointing to null, then that is where loop begins, in case array turn the positive integers in negative and if you come accross a negative integer then it is duplicated.\
    - Extra Space Method : use unordered_set to store the addresses of the nodes and in case of aray use maps. 
    - Optimisedd Method : Use `Floyd'd tortoise and hare algorithm` to detect cycle. It is kind of Two pointer approach, as one pointer is moving 1 at a time and another is moving 2 at a time.
- same algo can be applied to `find middle node in LL in O(n)`

<hr>

## Recursion & Backtracking

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

## Greedy Algos
- converting arrays to a structure and `comparators` for sorting structure
- Most commonly asked greedy algos
    - Activity Selection
    - Fractional Knapsack
    - Minimum No. of coins
    - >Job sequencing !!!


<hr>

## Binary Search
- Instead of `mid = start+end/2` use `mid = start + (end-start)/2`, to remove integer overflow
- In cases you dont know the high limit or the array is **infinite**, use Binary Search in reverse manner that is keep increasing the `high to 2*high and start to high` until condition is met.
- In hard questions, the basic goal should be
    - see and observe a monotonic f(n), and doing this might take time
    - this monotonic series will have a computation function, f(n) and initially dont mind it,
    - find a low and a high, generally it is based on the result domain of the question and then result is cross verified if it can make the question condition true.
    - f(n) is actually responsible for checking if the current value is valid or not.


<hr>

## Stacks and Queues
- Implementation Of Stacks 
    - Using Array
    - Using Linked List
- Implementation Of Queues
    - Using Array
    - Using Linked List
- Implementation Important Questions
    - [Min Stack](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380937) ; Create a stack to store new value if its less than top of min stack
    - [Stack Using 2 Queues](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380940) ; [Soln](https://www.youtube.com/watch?v=jDZQKzEtbYQ)
    - [Queue Using 2 Stacks](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380939) ; 
    - [Two Stacks](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380938) ; divides array in two stacks one from L one from R, R is given too.
    - [Implement A Deque](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118796/offering/1381380)
- Reverse Questions ; Undone
    - [Reverse A Queue](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380946) ; use a stack to reverse and then store back in the queue
    - Revese A Stack Using Another Stack ; pop from s1 and push to s2
    - [Reverse First K Elements Of Queue](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380947) ; move first k elements to a stack and then move back to a queue (Reverse a queue concept) and then just push rest of the elements from q1 to q2.
- Popular Applications
    - [LRU Cache Implementation](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380941) !!!!
    - [Evaluation Of Postfix Experession](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380942)
    - [Next Greater Element](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380943)
    - [Valid Paranthesis](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380944)
- Popular Interview Questions
    - [Sort A Stack](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380948)
    - [Delete Middle Element From Stack](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380949)
    - [Execution Time](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380951) !!!!
    - [Find the nearest supporter](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380952)
    - [Maximum of minimum for every window size](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118523/offering/1380950)


<hr>

## Trie
- Unacademy lectures 
- Strivers questions