- Detect cycle in un-directed graph?
    ```cpp
    // apply dfs and if some node is already visited then cycle except parent
    bool isCyclic(int i, int parent){
        vis[i] = true;
        for(auto it: list[i]){
            if(!vis[it]){
                if( isCyclic(it, i) )
                    return true;
            } else if(it != parent)
                return true;
        }
        return false;
    }
    bool isTree(){
        if(isCyclic(0, -1))
            return false;       // we have a cycle, so not tree
        
        for(int i=0 ; i<n ; ++i)
            if(!vis[i])
                return false;
        
        return true;
    }
    ```
- Detect cycle in directed graph, by same method?
    - we cant do same, because there might be a node that has outgoing edge but no incoming edge, and hence it will remain un-visited.
- Detect cycle in directed graph? Union-Find approach
    >NOTE - our parent is dest node, and we are checking if for an edge s and d have same parents (that is if they end up at the destination or not)

    > parent[dest] and source[dest] - this means, in findParent() `parent[dest] ko recursively find krna hai` whereas `source[dest] means parent[source] = dest` rkhna hai 
    ```cpp
    /* we use the concept of disjoint set approach, 
    where we basically treat every node as individual set initially */
    vector<int> parent(E, -1);
    
    /* for an edge, if source and dest have different parents (initially both source and dest index), 
    then we UNION them, we are baically unionising two sets into one, and treating the dest index as top, which can be used to identify a set (how to differentiate sets? by finding their tops using parent array)
    */
    if (findParent(edge[i].source) != findParent(edge[i].dest))
        parent[source] = dest; 
    
    /* this function is used to find the top of the set, this is done to identify the subset from the given item */
    int findParent(int item){
        if(parent[item] == -1)  return item;
        findParent(parent[item]);
    }
    
    // and hence this is how we use UNION-FIND to detect cycle and find MST (later on) for a graph
    ```