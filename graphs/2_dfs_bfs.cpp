#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph{
    int n;
    vector<int> *list;
    bool *visited;
    public:
        Graph(int node){
            n = node;
            list = new vector<int>[node];
            visited = new bool[node];
            for(int i=0 ; i<n ; ++i)
                visited[i] = false;
        }
        void addEdge(int s, int d){
            list[s].push_back(d);
            list[d].push_back(s);
        }
        void dfs(int i){
            visited[i] = true;
            cout << i << " ";
            for(auto it: list[i])
                if(!visited[it])
                    dfs(it);
        }
        void bfs(int start){
            for(int i=0 ; i<n ; ++i)
                visited[i] = false;
            queue<int> q;
            visited[start] = true;
            q.push(start);
            while(!q.empty()){
                int temp = q.front();
                cout << temp << " ";
                q.pop();
                for(auto it: list[temp]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it] = true;
                    }
                }
            }
        }
};

int main(){
    Graph g = Graph(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 4);
    g.dfs(0);
    cout << "\n";
    g.bfs(0);
    return 0;
}