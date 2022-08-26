#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define V 9

int weight[N];
bool visited[N];
int graph[N][N] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                    { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                    { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                    { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                    { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                    { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                    { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                    { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                    { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };


int findNextConnectedNode(){
    int minWt = INT_MAX, minIndex = -1;
    for(int i=0 ; i<N ; ++i){
        if(weight[i] < minWt && !visited[i]){
            minWt = weight[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void shortestPath(){
    int parent[N];

    for(int i=0 ; i<N ; ++i){
        visited[i] = false;
        weight[i] = INT_MAX;
    }

    parent[0] = -1;
    weight[0] = 0;
    for(int i=0 ; i<N-1 ; ++i){
        // tells us about the next adjacent node which has minimum weight and not visited.
        // initially it will give us 0 index bec its not visited and hence we
        // will get to see its adjacent nodeds
        int u = findNextConnectedNode();
        visited[u] = true;

        // after finding the node, now its adjacent are being observed and array is updated
        for(int v=0 ; v<N ; ++v){
            if(graph[u][v] != 0 && visited[v] == false && weight[u] != INT_MAX && weight[v] > weight[u] + graph[u][v]){
                parent[v] = u;
                weight[v] = graph[u][v];
            }
        }
    }
    for(int i=1 ; i<N ; ++i){
        cout << parent[i] << "--" << weight[i] << "-->" << i << "\n";
    }
}

int main(){
    shortestPath();
    return 0;
}