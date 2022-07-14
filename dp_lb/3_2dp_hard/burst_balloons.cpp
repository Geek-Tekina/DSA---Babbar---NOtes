#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int solve(int i, int j, vector<int> &nums, vector<vector<int>>& dp){
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int ans = 0;
    for(int index=i ; index<=j ; ++index){
        int coins = nums[i-1]*nums[index]*nums[j+1];
        int cost = coins + solve(i, index-1, nums, dp) + solve(index+1, j, nums, dp);
        ans = max(ans, cost);
    }
    return dp[i][j] = ans;
}
    

int main(){
    vector<int> nums = {3,1,5,8};
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
    cout << solve(1, n, nums, dp) << endl;
    return 0;
}