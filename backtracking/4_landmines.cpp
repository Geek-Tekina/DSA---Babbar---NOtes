#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int m[5][5] = {
    // {1, 1, 1, 1},
    // {1, 0, 1, 1},
    // {1, 1, 1, 1},
    // {1, 1, 1, 0},
    {1, 0, 1, 0, 0},
    {0, 0, 0, 1, 0},
    {1, 0, 1, 1, 1},
    {1, 1, 1, 0, 1},
    {1, 1, 0, 0, 0},
};
int n = 5;

void solve(int i, int j, bool **visited, int count){
    if(j == n-1){
        cout << count << endl;
        return;
    }

    // right
    if (j<n-1  && m[i][j+1] && !visited[i][j+1]){
        visited[i][j+1] = true;
        solve(i, j+1, visited, count+1);
        visited[i][j+1] = false;
    }

    // DOWN
    if (i<n-1 && m[i+1][j] && !visited[i+1][j]){
        visited[i+1][j] = true;
        solve(i+1, j, visited, count+1);
        visited[i+1][j] = false;
    }

    // LEFT
    if (j>0 && m[i][j-1] && !visited[i][j-1]){
        visited[i][j-1] = true;
        solve(i, j-1, visited, count+1);
        visited[i][j-1] = false;
    }

    // UP
    if (i>0 && m[i-1][j]  && !visited[i-1][j]){
        visited[i-1][j] = true;
        solve(i-1, j, visited, count+1);
        visited[i-1][j] = false;
    }

}

int main(){
    bool **v;
    v = new bool*[n];
    for(int i=0 ; i<n ; ++i)
        v[i] = new bool[n];

    // modify array

    for(int i=0 ; i<n ; ++i)
        solve(i,0, v, 0);
    
    return 0;
}