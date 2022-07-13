#include <iostream>
#include <vector>
#include <climits>
using namespace std;
// https://leetcode.com/problems/minimum-sideway-jumps/discuss/2214854/C%2B%2B-tabulation-code

// just do only memoization
int solve(int froglane, int i, vector<int> &obs){
    if(i == obs.size())    return 0;
    
    // no collision
    if(froglane != obs[i+1])
        return solve(froglane, i+1, obs); 
    else {
        int ans = INT_MAX;
        for(int x=1 ; x<=3 ; ++x){
            // now kinda bruteforce but we will check
            // out of all 3 possible lane which are valid to go
            // and "go" means just changing froglane and not index
            // cond1. no obs should be at x in current index
            //      x != obs[i]
            // cond2. no obs should in front of "to jump" lane
            //      x != obs[i+1]
            if(x != obs[i] && obs[i+1] != x)
                ans = min(ans, solve(x, i, obs) + 1);
        }
        return ans;
    }
}

int main(){
    vector<int> obs = {0,1,2,3,0};
    cout << solve(2, 0, obs) << endl;
    return 0;
}