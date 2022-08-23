#include <iostream>
#include <vector>
#include <climits>
using namespace std;
typedef vector<vector<int>> vvi;

int rec(vector<int> &coins, int left, int index, vvi &dp){
    if(left == 0)   return dp[left][index] = 0;
    if(index == 0)   return dp[left][index] = -1;

    if(dp[left][index] != -2)   return dp[left][index];
    if(left >= coins[index-1]){
        int ans1 = rec(coins, left, index-1, dp);
        int ans2 = rec(coins, left-coins[index-1], index, dp);
        int ans;
        if(ans1 == -1 && ans2 == -1)   ans = -1;
        else if(ans1 == -1)   ans = ans2 + 1;
        else if(ans2 == -1)   ans = ans1;
        else   ans = min(ans1, ans2+1);
        return dp[left][index] = ans;
    } else {
        return dp[left][index] = rec(coins, left, index-1, dp);
    }
}

int main(){
    vector<int> coins = {1,2,3,4,5};
    int target = 20;
    vvi dp = vvi(target+1, vector<int>(coins.size()+1, -2));
    cout << rec(coins, target, coins.size(), dp) << endl;
    return 0;
}