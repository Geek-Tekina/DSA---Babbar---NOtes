#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int orangesRotten(vvi &grid){
    int rows = grid.size();
    int cols = grid[0].size();
    int goodOranges = 0;
    queue<pair<int, int>> rottenOranges;
    for(int i=0 ; i<rows ; ++i){
        for(int j=0 ; j<cols ; ++j){
            if(grid[i][j] == 1) ++goodOranges; 
            else if(grid[i][j] == 2)    rottenOranges.push({i, j});
        }
    }

    int time = 0;
    if(goodOranges == 0)    return 0;
    while(!rottenOranges.empty()){
        int thisRound = rottenOranges.size();
        while(thisRound--){
            pair<int, int> curr = rottenOranges.front();
            rottenOranges.pop();
            int i = curr.first;
            int j = curr.second;
            if(i-1 >= 0 && grid[i-1][j] == 1){
                grid[i-1][j] = 2;
                rottenOranges.push({i-1, j});
                --goodOranges;
            }
            if(i+1 < rows && grid[i+1][j] == 1){
                grid[i+1][j] = 2;
                rottenOranges.push({i+1, j});
                --goodOranges;
            }
            if(j-1 >= 0 && grid[i][j-1] == 1){
                grid[i][j-1] = 2;
                rottenOranges.push({i, j-1});
                --goodOranges;
            }
            if(j+1 < cols && grid[i][j+1] == 1){
                grid[i][j+1] = 2;
                rottenOranges.push({i, j+1});
                --goodOranges;
            }
        }
        if(!rottenOranges.empty()) ++time;
    }
    return goodOranges == 0 ? time : -1;
}

int main() {
    vvi grid = {{2,1,1},{1,1,0},{0,1,1}};
    cout << orangesRotten(grid) << endl;
}