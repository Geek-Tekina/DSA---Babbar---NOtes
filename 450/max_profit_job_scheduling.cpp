#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

int solve(vi &startTime, vi &endTime, vi &profit, int et, vi &dp){
    int res = 0;
    if(dp[et] != -1)    return dp[et];

    for(int i=0; i<startTime.size(); ++i){
        if(startTime[i]>=et)
            res = max(res, profit[i] + solve(startTime, endTime, profit, endTime[i], dp) );
    }
    return dp[et] = res;
}

int jobScheduling(vi &startTime, vi &endTime, vi &profit){
    int max_et_value = 0;
    for(int i=0; i<endTime.size(); ++i)
        max_et_value = max(max_et_value, endTime[i]);
    vector<int> dp(max_et_value + 1, -1);
    
    return solve(startTime, endTime, profit, 1, dp);
}

int main(){
    vi startTime = {1,2,3,3};
    vi endTime = {3,4,5,6};
    vi profit = {50,10,40,70};
    cout << jobScheduling(startTime, endTime, profit) << endl;
    return 0;
}