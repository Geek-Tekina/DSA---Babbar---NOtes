#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define V 5

int graph[V][V] = {{0, 2, 0, 6, 0},
                   {2, 0, 3, 8, 5},
                   {0, 3, 0, 0, 7},
                   {6, 8, 0, 0, 9},
                   {0, 5, 7, 9, 0}};


int findNextConnectedNode(int weight[], bool visited[]){
    int minWt = INT_MAX, minIndex = -1;
    for(int i=0 ; i<V ; ++i){
        if(weight[i] < minWt && !visited[i]){
            minWt = weight[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void prims(){
    int parent[V];
    int weight[V];
    bool visited[V];
    for(int i=0 ; i<V ; ++i){
        visited[i] = false;
        weight[i] = INT_MAX;
    }

    parent[0] = -1;
    weight[0] = 0;
    visited[0] = true;
    for(int i=0 ; i<V-1 ; ++i){
        // tells us about the next adjacent node which has minimum weight and not visited
        int u = findNextConnectedNode(weight, visited);
        visited[u] = true;

        // after finding the node, now its adjacent are being observed and arrays are updated
        for(int v=0 ; v<V ; ++v){
            if(graph[u][v] != 0 && visited[v] == false && weight[v] > graph[u][v]){
                parent[v] = u;
                weight[v] = graph[u][v];
            }
        }
    }
    for(int i=0 ; i<V ; ++i){
        cout << parent[i] << "--" << weight[i] << "-->" << i << "\n";
    }
}

int main(){
    prims();
    return 0;
}