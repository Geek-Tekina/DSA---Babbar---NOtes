#include <queue>
using namespace std;

int orangesRotting(vector<vector<int>> &grid){
    queue<pair<int, int>> q;
    int total = 0, count = 0, result = 0;
    for (int i = 0; i < grid.size(); ++i){
        for (int j = 0; j < grid[i].size(); ++j){
            if (grid[i][j] != 0) ++total;
            if (grid[i][j] == 2)    q.push({i, j});
        }
    }

    int dx[4] = {0, 1, 0,-1};
    int dy[4] = {-1,0, 1, 0};

    while(!q.empty()){
        int size = q.size();
        count += size;
        while(size--){
            int x = q.front().first, y = q.front().second;
            for(int i=0 ; i<4 ; ++i){
                int nx = x+dx[i], ny = y+dy[i];
                if(nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] !=1 )
                    continue;
                grid[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
        if(!q.empty())  ++result;
    }
    return total == count ? result : -1;
}