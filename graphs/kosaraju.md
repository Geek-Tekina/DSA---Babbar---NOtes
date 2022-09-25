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