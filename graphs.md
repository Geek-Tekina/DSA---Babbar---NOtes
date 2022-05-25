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
    - [Is Graph Connected?](graphs/3_graph_connected.cpp) 
    - Print All Connected Components Of Graph ; jusst put a parent loop and then call dfs/ bfs
- Applications Of BFS/DFS
    - [Is graph tree or not](graphs/4_is_tree.cpp)
    - [Graph coloring](graphs/5_graph_coloring.cpp)
    - [Maximum Island length](https://www.geeksforgeeks.org/find-length-largest-region-boolean-matrix/)
        ```md
        approach here is that
            - create a similar sized visited 2d boolean matrix and set to false.
            - iterate the 2d matrix
            - if you encounter 1, and it is not visited, then apply dfsCheck on it
            - 
            - dfsCheck()? it will check the adjacent 8 cells, and if it is 1 then again check that cell adjacent, but make sure to mark the cells as visited to prevent it from infinite loop.
            - use a count counter to store the temp answer
        ```
- MST
    - [Detect cycle in Directed Graph](graphs/5_union-find.md)
    - [Kruskal's Algo](graphs/5_kruskal.cpp) ;  same as above
    - [Prims's Algo](graphs/6_prims.cpp)
- [Dijkstra](graphs/7_dijkstra.cpp)
    - the notes must be positive and no-negative-cycles
    - the code is same as prim's only the relaxation is updated
    - for prims it was `weight[v] > graph[u][v]`, where we are checking Node_V->B is better or previousNode->B
    - for dijsktra it is, `weight[u] != INT_MAX && weight[v] > weight[u] + graph[u][v]`, where first we are checking the current node is not infinity and then relax it.