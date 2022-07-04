#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &nums, int n){
    if(n <= 0) return 0;
    else {
        return max(solve(nums, n-2) + nums[n-1], solve(nums, n-1));
    }
}

int dp(vector<int> &nums){
    int n = nums.size();
    int t[n+1];

    t[0] = 0;
    t[1] = nums[0];
    for(int i=2; i<=n; ++i){
        t[i] = max(t[i-2] + nums[i-1], t[i-1]);
    }
    return t[n];
}

int main(){
    vector<int> nums2 = {3,2,5,10,7};
    vector<int> nums = {2,3,7,10};

    cout << solve(nums, nums.size()) << endl << dp(nums) << endl;
    return 0;
}