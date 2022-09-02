## Greedy Algos
Optimization questions can be solved Greedy Approach. It says problem should be solved in stages and in each stage, __we will consider one input from a given problem__ AND __if that input is feasible then we will include it in the solution, so by including all those feasible solution we can get the optimal solution__.

A general approach can be given by, where a is the array with inputs. 
```
for i = 1 to n 
    x = select(a)
    if feasible(x) then
        solution = solution + x
```
<!-- - converting arrays to a structure and `comparators` for sorting structure -->

### Basic Quesitions
1. __Activity Selection__ [(gfg)](https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/)
1. N Meetings [(striver)](https://takeuforward.org/data-structure/n-meetings-in-one-room/) - Activity selection based
1. Fractional Knapsack [(striver)](https://takeuforward.org/data-structure/fractional-knapsack-problem-greedy-approach/)
1. Minimum No. of coins -
    ```cpp
    i = coins.size() - 1;
    // we know the biggest coin is the last one so that that as many as possible
    res = v / coins[i]    
    v %= coins[i]    
    while(v!=0)
        if(v >= coins[i])    ++res, v -= coins[v];
        else    --i;
    ``` 
1. Train - Platform based
    1. Max trains that can board the platform - Activity Selection Based
    1. [Max trains that can board the platform (with n-platforms)](https://www.geeksforgeeks.org/maximum-trains-stoppage-can-provided/) - basically Q1 but n times. 
    1. __Min platforms required to board all the trains__ - [code](greedy/min_platforms.cpp)
1. __Job sequencing__ [(striver)](https://takeuforward.org/data-structure/job-sequencing-problem/) - [code](greedy/job_sq.cpp)

### 450 Sheet - Greedy based questions
1. 245 Min and Max cost to buy all candies - to find min cost, logically we want to buy all cheaper candies and eliminate the `k` expensive ones, which can be done by sorting and using two pointer approach. Do similar for max cost. 
1. 323 Gas Station [(youtube)](https://www.youtube.com/watch?v=7WYwqvOSaa8&ab_channel=CodeLibrary-byYogesh%26Shailesh) - [code](greedy/gas_stn.cpp)


