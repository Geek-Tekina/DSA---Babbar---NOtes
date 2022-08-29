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
    while(v!=0)
        if(v >= coins[i])    ++res, v -= coins[v];
        else    --i;
    ``` 
1. Train - Platform based
    1. Max trains that can board the platform - Activity Selection Based
    1. [Max trains that can board the platform (with n-platforms)](https://www.geeksforgeeks.org/maximum-trains-stoppage-can-provided/) - basically Q1 but n times. 
    1. __Min platforms required to board all the trains__ - [code](greedy/min_platforms.cpp)
1. __Job sequencing__ [(striver)](https://takeuforward.org/data-structure/job-sequencing-problem/) - [code](greedy/job_sq.cpp)

### Questions & Playlist to do
1. Gas Station [(youtube)](https://www.youtube.com/watch?v=xmJZSYSvgfE&ab_channel=KnowledgeCenter) - [leetcode](https://leetcode.com/problems/gas-station/)
1. [Greedy Algorithm Faraz](https://www.youtube.com/watch?v=lZJGbS12mWo&list=PLQXZIFwMtjozzDH4ZRtpIl0piBjsRF5Bf&index=6&ab_channel=CodeChef)
1. [Keerti purswani Mock Interview with Riddhi Dutta](https://www.youtube.com/watch?v=r2w_r4U67Nc&ab_channel=RiddhiDutta)  -->

### 450 Sheet - Greedy based questions
<!-- - [Merge Intervals](https://www.geeksforgeeks.org/merging-intervals/) -->

