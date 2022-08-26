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
1. Activity Selection - [read from gfg](https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/)
1. N Meetings - Its approach is totally similar to the Activity selection problem. [read from striver](https://takeuforward.org/data-structure/n-meetings-in-one-room/)
1. Fractional Knapsack - [read from striver](https://takeuforward.org/data-structure/fractional-knapsack-problem-greedy-approach/)
1. Minimum No. of coins -
    ```cpp
    i = coins.size() - 1;
    while(v!=0)
        if(v >= coins[i])    ++res, v -= coins[v];
        else    --i;
    ``` 

<!-- - [Min Platforms](https://www.youtube.com/watch?v=dxVcMDI7vyI&list=PLgUwDviBIf0p4ozDR_kJJkONnb1wdx2Ma&index=47)
    - Job sequencing
    - [Merge Intervals](https://www.geeksforgeeks.org/merging-intervals/)


- [Gas Station Greedy Leetcode](https://leetcode.com/problems/gas-station/) : [youtube](https://www.youtube.com/watch?v=xmJZSYSvgfE&ab_channel=KnowledgeCenter)
- [Greedy Algorithm Faraz](https://www.youtube.com/watch?v=lZJGbS12mWo&list=PLQXZIFwMtjozzDH4ZRtpIl0piBjsRF5Bf&index=6&ab_channel=CodeChef)
- [Keerti purswani Mock Interview with Riddhi Dutta](https://www.youtube.com/watch?v=r2w_r4U67Nc&ab_channel=RiddhiDutta)  -->