#include <iostream>
#include <vector>
using namespace std;

/*
how to detect tree? it has to acyclic and all the nodes connected
we are using dfs approach to visit every node, if any node is already visited
and its not the node's parent then theres a cycle.

we are returning only if isCyclic is true, if recursively 
called isCylic returns false,then we dont want to stop right now.
and atlast if there were no cycle then the first called 
isCylic's return false will be executed
*/

class Graph {
    int n;
    vector<int> *list;
    bool *vis;
    public:
        Graph(int nodes){
            n = nodes;
            list = new vector<int>[n];
            vis = new bool[n];
        }
        addEdge(int s, int d){
            list[s].push_back(d);
            list[d].push_back(s);
        }
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
};

int main(){
    Graph g = new Graph(5);
    return 0;
}