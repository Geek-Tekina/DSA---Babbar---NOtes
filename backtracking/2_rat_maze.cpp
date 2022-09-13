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
    if(i>=0 and i<n and j>=0 and j<n and visited[i][j]==false and m[i][j]) { 
        visited[i][j] = true;

        solve(i, j+1, visited, op + 'R');        
        solve(i+1, j, visited, op + 'D');
        solve(i, j-1, visited, op + 'L');        
        solve(i-1, j, visited, op + 'U');
        // instead of creating a new visited 2d matrix for each call, 
        // we can just mark the current cell as visited and then backtrack
        
        visited[i][j] = false;
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
    solve(0, 0, visited, "");
    return 0;
}