#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vector<bool>> vvb;

int solve(int i, int j, int n, vvi &grid, vvb &visited, vvi &dp){
    if(i == n-1 and j == n-1)
        return 0;
    if(i>=0 and i<n and j>=0 and j<n){
        
        // we know the answer will be minimum bec if we reach first then its ofc mini
        // agar i j direct pahuch rahe hai tou that is only min and agar ab loop krke pahuche tou it wont be minimum
        if(visited[i][j])   return dp[i][j];
        visited[i][j] = true;
        // no need to mark vis ij as false because once we reach here
        // we get our answer
        // and the answer is minimum : read above

        // we can go either right or bottom
        return dp[i][j] = 1 + min(solve(i + grid[i][j], j, 3, grid, visited, dp), solve(i, j + grid[i][j], 3, grid, visited, dp));
    } else return 1e4;
}

int main(){
    vvi mat = {{2, 1, 2},
           {1, 1, 1},
           {1, 1, 1}};
    vvb visited(3, vector<bool>(3, false));
    vvi dp(3, vi(3, 0));
    cout << solve(0, 0, 3, mat, visited, dp) << endl;
    // print dp
    for(auto &v : dp){
        for(auto &i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}