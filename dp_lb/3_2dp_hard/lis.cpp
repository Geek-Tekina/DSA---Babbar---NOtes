#include <iostream>
#include <vector>
using namespace std;
typedef vector<vector<int>> vvi;


class Solution {
public:
    int solve(vector<int>& nums, int p, int c, vvi &t){
        if(c == nums.size()){    
            return 0;
        }
        if(p != -1 && t[p][c]!=-1)   return t[p][c];
        
        int pick=0;
        if(p == -1 ||  nums[c]>nums[p]) 
            pick = 1 + solve(nums, c, c+1, t);
        int dontpick = solve(nums, p, c+1, t);
        
        if(p != -1)     t[p][c] = max(pick, dontpick);
        return max(pick, dontpick);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        // with the value as 0 here we were getting TLE
        // bec even after processing a lot of cells were 0 already
        vvi t(nums.size(), vector<int>(nums.size(), -1));
        return solve(nums, -1, 0, t);
    }
};

int main(){
    return 0;
}