### Binary Search
- Instead of `mid = start+end/2` use `mid = start + (end-start)/2`, to remove integer overflow
- In cases you dont know the high limit or the array is **infinite**, use Binary Search in reverse manner that is keep increasing the `high to 2*high and start to high` until condition is met.
- if key is not found then, `start -> i and end -> i-1`, hence neighbour elements
- In hard questions, the basic goal should be
    - see and observe a monotonic f(n), and doing this might take time
    - this monotonic series will have a computation function, f(n) and initially dont mind it,
    - find a low and a high, generally it is based on the result domain of the question and then result is `cross verified` if it can make the question condition true.
    - f(n) is actually responsible for checking if the current value is valid or not.
    - `cross-verification` is the most important part, where you check if the current value is valid or not.

### Easy-Med Questions
- __Bitonic Array__
- __Find peak element__
- __Find first and last occurence of a number__
- __Find floor and ciel__ (use conept of neighbour elements)

### Medium-Hard Questions
- __Find nth root of number__
- __Find element that has single occurence in a sorted array__ (concept of indexing)
- __Allocate minimum pages to students__
- __Aggresive cows__