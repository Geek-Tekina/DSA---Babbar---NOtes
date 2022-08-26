#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef vector<vector<int>> vvi;

int solve(vvi distance, int N, int K){
    int fcity = K-1;
    vector<int> route;
    int s=0;
    int min_path = INT_MAX;
    for (int i = 0; i < N; i++)
        if (i != s) route.push_back(i);
 
    do {
        int current_pathweight = 0;
        int k = s;
        for (int i = 0; i < route.size(); i++) {
            current_pathweight += distance[k][route[i]];
            k = route[i];
        }
        // this is for last city to first city path
        // current_pathweight += graph[k][s]; 

        // custom one
        current_pathweight += distance[route[route.size()-1]][fcity];
        current_pathweight += distance[fcity][s];
        min_path = min(min_path, current_pathweight);

    } while ( next_permutation(route.begin(), route.end()) );
 
    return min_path;
}
 
int main() {
    vvi graph =        { { 0, 1, 5, 6 },
                       { 2, 0, 7, 3 },
                       { 9, 6, 0, 12 },
                       { 10, 4, 8, 0 } };
    cout << solve(graph, graph.size(), 2) << endl;
    return 0;
}