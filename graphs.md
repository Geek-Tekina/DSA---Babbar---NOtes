- **for Reff** : https://dynalist.io/d/s_rF6jbfCEbqLFmkA_NMC90s

## Graphs
- Pre-requisite - [pointers](pointers.cpp)
- **[Introduction - representaion, terms](https://www.programiz.com/dsa/graph)**
    ```cpp
    g.add(0,2);     // whenever we add an edge like this, we basically
    matrix[0][2] = matrix[2][0] = 1;
    list[0].push_back(2);    list[2].push_back(0);
    ```
- **VVVIMP : [Basic Code](graphs/1_basic.cpp)** 
- Basic BFS/ DFS Questions
    - [Depth First](graphs/2_dfs_bfs.cpp)
    - [Breadth First](graphs/2_dfs_bfs.cpp)
    - [Is Graph Connected or Strongly connected components in a graph?](graphs/3_graph_connected.cpp) 
        - Undirected? basic dfs and then check visited array 
        - Directed? Kosaraju Algorithm
            - Create clone reversed graph
                ```cpp
                vector<int> rEdges[V];         // 2d array
                for(int s=0 ;s<V ; ++s)
                    for(auto dest: edges[s])
                        rEdges[dest].push_back(s);
                ```
            - Generate order vector i.e. a vector of nodes in the order in which they are visited while returning from dfs call e.g. 1->(4->null and 2->3->null) then 3 is pushed first, then 2, then if 4 and then finally 1.
                ```cpp
                vector<int> order;
                vector<bool> vis(V, false);
                for(int i=0 ; i<V ; ++i)
                    if(!vis[i])
                        dfs(i, vis, order);
                
                dfs(int src, vector<bool> &vis, vector<int> &order){
                    after for loop
                    order.push_back(src);
                }
                ```
            - Now run dfs on reversed graph in the order vector i.e. from last to first, and ___number of dfs calls = answer___
                ```cpp
                int count=0;
                vector<bool> vis(V, false);
                for(int i=V-1 ; i>=0 ; --i)
                    if(!vis[i])
                        dfs(i, vis, order), ++count;
                ```
- Applications Of BFS/DFS
    - [Is graph tree or not](graphs/4_is_tree.cpp)
    - [Graph coloring](graphs/5_graph_coloring.cpp)
    - [Maximum Island length](https://www.geeksforgeeks.org/find-length-largest-region-boolean-matrix/)
        ```md
        approach here is that
            - create a similar sized visited 2d boolean matrix and set to false.
            - iterate the 2d matrix
            - if you encounter 1, and it is not visited, then apply dfsCheck on it
            - dfsCheck()? it will check the adjacent 8 cells, and if it is 1 then again check that cell adjacent, but make sure to mark the cells as visited to prevent it from infinite loop.
            - use a count counter to store the temp answer
        ```
    - [Rotten Oranges](graphs/9_rotten_oranges.cpp) ; similar logic for [Shortest Path in Binary Matrix](https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118511/offering/1381547?leftPanelTab=3)
        ```cpp
        /*
        while dealing with logic of BFS and "parallely processing",
        queues should be used to process the elements, and
        get the size of the queue and then in one iteration process thee elements till these size 
        */
        while(!q.empty()){
            int size = q.size();
            while(size--) { /* */ }
        }
        ```
- Famous Algos
    - [Union Find/ Disjoint Set](graphs/5_union-find.md) - Detect cycle in Directed Graph
    - [Kruskal's Algo](graphs/5_kruskal.cpp) - for MST
        - just sort edges and then apply union-find for E-1 edges same as above
    - [Prims's Algo](graphs/6_prims.cpp) - for MST
        - parent array : storing, `p[v]=u`, that is source value @dest, dest's(p[i]) parent will be what? i.
        - weight array : to store the weight of the visited and adjacent nodes, else INT_MAX
        - visited array
    - [Dijkstra](graphs/7_dijkstra.cpp) - shortest path between any two nodes in a graph but +ve
        - the notes must be positive and no-negative-cycles
        - the code is same as prim's only the relaxation is updated
        - for prims it was `weight[v] > graph[u][v]`, where we are checking Node_V->B is better or previousNode->B
        - for dijsktra it is, `weight[u] != INT_MAX && weight[v] > weight[u] + graph[u][v]`, where first we are checking the current node is not infinity and then relax it.
    - Floyd's Warshall - shortest path between any two nodes in a graph but +ve -ve, both
        - relaxation logic is `dij = min(dij, dik + dkj), for k=1ton, i=0ton and j=0ton`
    - [Kahn's Algo or Topological Sorting](graphs/8_topological.cpp)
    - Kosaraju Algorithm __read above__


<hr>


#### Misc - Imp
- ___Rat in a maze vs Min Steps to reach target___
    - In rat in a maze, we have to find all the paths and hence backtracking (+dfs) is only option.
    - [MUST!! read code to avoid using extra memory](backtracking/2_rat_maze.cpp)
    - In Min Steps to reach target, Naive approach is that we can backtrack and hence O(pow(2, n)) complexity.
    - But we also know that there's no need to traversing all the paths because the moment we reach the target, we found the minimum steps.
    - HOW?? it is only logical because if we are reaching first then its the direct direction, else we are forming loop for no reason.
    - AND HENCE, no need to set visited[i,j] as false after backtracking, because we are not going to visit it again.
    - [MUST!! read the code]((graphs/11_min_steps_reach_target.cpp))
- [Min steps by knight](graphs/10_steps_knights.cpp) - it is kinda similar but not possoble with dfs but why?? 
    - because unlike tree, a graph dfs traversal can be a bit lengthy (depending upon the question). 
    - We have to use BFS here because BFS works in parallel for all the approachable path
    - so whenever we reach the destination with any path then ___that first path will always be minimum.___ 
    - And this is why we have to use BFS as it works in parallel. 
    - And we can not use DFS here because with DFS we will keep on moving in depth till we either reach the destination or we visit all the cells and no more cells to visit. 
    - ___And so then we will backtrack and then we will try another path and with that another path suppose we are able to reach then we can not be sure that this is path is minimum path only.___ 
    - Because DFS does not work in parallel. And so if we are using DFS then we have to use traverse all the possible paths and then only we can select minimum out of all of them. But with BFS first path with which we reach destination is always be the minimum path.
- [Min cost to destination](graphs/12_min_cost_dest.cpp)
    - why visited is set to 1 but never switched back to 0??? 
    - and iknow its not backtracking if we not resetting to 0, but then why not backtrack?
    - also, the order of recursive call matters, maybe thats why?

<img src=".assets/graph1.png">