#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define NODES 6

/*
in topological sort, nodes with indegree 0 are first processed
and then the edges outgoing from this node are removed making other nodes'
indegree tends to 0
indegree array :  to store initial indegree
queue : to process indegree-0 nodes in FCFS manner
*/

vector<int> *list;

void kahn(){
    int indegree[NODES];
    for(int i=0 ; i<NODES ; ++i)
        indegree[i] = 0;

    for(int i=0 ; i<NODES ; ++i)
        for(auto it : list[i])
            ++indegree[it];
    
    queue<int> q;
    for(int i=0 ; i<NODES ; ++i)
        if(indegree[i] == 0){
            q.push(i);
            indegree[i] = -1;
        }

    while(!q.empty()){
        int source = q.front(); 
        cout << source; 
        q.pop();
        for(auto it: list[source]){
            --indegree[it];
            if(indegree[it] == 0){
                q.push(it);
            }
        }
    }

}

int main(){
    list = new vector<int>[NODES];
    list[0].push_back(1);
    list[0].push_back(3);
    list[1].push_back(2);
    list[1].push_back(3);
    list[2].push_back(3);
    list[2].push_back(4);
    list[2].push_back(5);
    list[3].push_back(4);
    list[3].push_back(5);
    list[4].push_back(5);

    kahn();

    return 0;
}