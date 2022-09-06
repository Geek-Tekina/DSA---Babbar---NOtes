#include <iostream>
#include <vector>
using namespace std;

/*
Q. How can one be assure that the first hit to the target cell would be of minimum step 
(since the function is returning the distance as soon as we reach to target, 
it might be that the first hit to the target cell would be of maximum step) ?
But according to me we should have a variable which will keep track of the minimum value 
and at last when the queue becomes empty we will return the value. 

A. The first hit will be the shortest due to specific of BFS algorithm. 
It checks every other cell that we can reach from the current and 
we don't reach it with the current step then iterates the number of steps by 1.
That way the first hitting of the target cell will be the correct number of steps.
Nevertheless that implementation won't show you if there are several ways of 
getting target position with the minimum number of steps.
*/

int solve(int i, int j, vector<vector<bool>> &visited, vector<int> &target, vector<vector<int>> &dp){
    int n = visited.size();
    if(i == target[0] and j == target[1]){
        return 0;
    }
        
    if(i>=0 and i<n and j>=0 and j<n){
        if(visited[i][j] == true)   return dp[i][j];
        visited[i][j] = true;

        // from all the paths find min one
        int ans = solve(i-1, j+2, visited, target, dp);
        ans = min(ans, solve(i-2, j-1, visited, target, dp));
        ans = min(ans, solve(i-1, j-2, visited, target, dp));
        ans = min(ans, solve(i+1, j-2, visited, target, dp));
        ans = min(ans, solve(i+2, j-1, visited, target, dp));
        ans = min(ans, solve(i-2, j+1, visited, target, dp));
        ans = min(ans, solve(i+1, j+2, visited, target, dp));
        ans = min(ans, solve(i+2, j+1, visited, target, dp));
        return dp[i][j] = 4 + ans;
    } else return 1e3;
}

int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N){
    --TargetPos[0]; --TargetPos[1];
    int i = KnightPos[0] - 1, j = KnightPos[1] - 1;
    vector<vector<bool>> vis(N, vector<bool>(N, false));
    vector<vector<int>> dp(N, vector<int>(N, 0));
    int a = solve(i, j, vis, TargetPos, dp);
    // print dp table
    for(int i=0 ; i<N ; ++i){
        for(int j=0 ; j<N ; ++j)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    return a;
}

int main(){
    int N=6;
    vector<int> knightPos = {4, 5};
    vector<int> targetPos = {1, 1};
    cout << minStepToReachTarget(knightPos, targetPos, N) << endl;
    return 0;
}