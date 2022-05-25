#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> parent(5, -1);

// this function is used to find the top root for the set
// this is done to identify the subset from the given item
int findParent(int item){
    if(parent[item] == -1)  return item;
    findParent(parent[item]);
}

class Edge {
    public:
        int source, dest, wgt;
        void set(int s, int d, int w){
            source = s; dest = d; wgt = w;
        }
        void print(){
            cout << source << "--" << wgt << "-->" << dest << "\n"; 
        }
};

bool compare(Edge e1, Edge e2){
    return e1.wgt < e2.wgt;
}

void kruskal(Edge *edgeList, int n, int E){
    sort(edgeList, edgeList + E, compare);

    int count=0, i=0;
    while(count < n){
        // "find" logic to detect cycle
        int sourceParent = findParent(edgeList[i].source);
        int destParent = findParent(edgeList[i].dest);

        // check if they belong to the same set, if YES then cycle.
        if (sourceParent != destParent) {
            edgeList[i].print();
            ++count;
            // "union" logic to merge the sets as one
            parent[sourceParent] = destParent; 
        }
        ++i;
    }
}


int main(){
    Edge *edgeList = new Edge[5];
    edgeList[0].set(0, 1, 10);
    edgeList[1].set(0, 2, 5);
    edgeList[2].set(1, 2, 4);
    edgeList[3].set(1, 3, 2);
    edgeList[4].set(2, 3, 3);

    kruskal(edgeList, 5, 5);

    return 0;
}