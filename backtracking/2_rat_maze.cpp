#include <iostream>
#include <vector>
#include <string>
using namespace std;

int m[4][4] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}};
    int n=4;

void solve(int i, int j, bool **visited, string op){
    if (i == n-1 && j == n-1){
        cout << op << endl;
        return;
    }

    // RIGHT
    if (j<n-1  && m[i][j+1] && !visited[i][j+1]){
        visited[i][j+1] = true;
        solve(i, j+1, visited, op + 'R');
        visited[i][j+1] = false;
    }

    // DOWN
    if (i<n-1 && m[i+1][j] && !visited[i+1][j]){
        visited[i+1][j] = true;
        solve(i+1, j, visited, op + 'D');
        visited[i+1][j] = false;
    }

    // LEFT
    if (j>0 && m[i][j-1] && !visited[i][j-1]){
        visited[i][j-1] = true;
        solve(i, j-1, visited, op + 'L');
        visited[i][j-1] = false;
    }

    // UP
    if (i>0 && m[i-1][j]  && !visited[i-1][j]){
        visited[i-1][j] = true;
        solve(i-1, j, visited, op + 'U');
        visited[i-1][j] = false;
    }
}

int main(){
    bool **visited;
    visited = new bool* [n];
    for(int i=0 ; i<n ; ++i){
        visited[i] = new bool[i];
        for(int j=0 ;  j<n ; ++j)
            visited[i][j] = false;
    }
    // cout << visited[1][2];
    solve(0, 0, visited, "");
    return 0;
}