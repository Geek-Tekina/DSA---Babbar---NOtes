#include <iostream>
#include <climits>
#include <vector>
using namespace std;

//mcm based
int solve(int i, int j, auto &dp){
    if(i>=j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int ans = INT_MAX;
    for(int k=i; k<j; k++){
        int cost = k + max( solve(i, k-1, dp), solve(k+1, j, dp));
        ans = min(ans, cost);
    }
    return dp[i][j] = ans;
}

int main(){
    int n = 10;
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    cout << solve(1, n, dp) << endl;
    return 0;
}