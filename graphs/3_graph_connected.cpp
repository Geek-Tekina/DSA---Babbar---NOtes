#include <iostream>
#include <vector>
using namespace std;

class Graph{
    int n = 4;
    vector<int> list[4];
    bool visited[4];
    
    public:
    void addEdge(int s, int d){
        list[s].push_back(d);
        list[d].push_back(s);
    }

    void dfs(int i){
        visited[i] = true;
        for(auto it: list[i])
            if(!visited[it])
                dfs(it);
    }

    void isConnected(){
        dfs(0);
        for(int i=0 ; i<n ; ++i){
            if(!visited[i]){
                cout << "not ";
            }
        }
        cout << "connected";
    }
};

int main(){
    Graph g = Graph();
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.isConnected();
    return 0;
}