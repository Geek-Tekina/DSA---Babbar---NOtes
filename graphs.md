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