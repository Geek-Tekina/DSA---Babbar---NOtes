#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
bool reachedToBottom = false;
int goup(vvi grid, int i, int j){
    if(i == 0 && j == 0) return grid[i][j];
    if(i > 0 && j > 0){
        if (grid[i][j] == -1)   return 0;
        int temp = grid[i][j];
        grid[i][j] = 0;
        return temp + max(goup(grid, i-1, j), goup(grid, i, j-1));
    }
    return 0;
}

int godown(vvi grid, int i, int j){
    if(i == grid.size() -1 && j == grid[0].size() -1) {
        reachedToBottom = true;
        int temp = grid[i][j];
        grid[i][j] = 0;
        return temp + goup(grid, i, j);
    } else if(i < grid.size() && j < grid[i].size()){
        if (grid[i][j] == -1)   return 0;
        int temp = grid[i][j];
        grid[i][j] = 0;
        return temp + max(godown(grid, i+1, j), godown(grid, i, j+1));
    }
    return 0;
}

int cherryPickup(vector<vector<int>>& grid) {
    int ans = godown(grid, 0, 0);
    return reachedToBottom ? ans : 0;
}

int main(){
    // vvi grid = {{1,1,-1},{1,-1,1},{-1,1,1}};
    vvi grid = {{0,1,-1},{1,0,-1},{1,1,1}};
    cout << cherryPickup(grid) << endl;
    return 0;
}