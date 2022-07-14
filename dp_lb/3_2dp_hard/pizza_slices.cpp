#include <bits/stdc++.h>
#include <vector>
using namespace std;

int dp[501][200];
int solve(int i, int n, vector<int> &slices){
    if(n==0 || i>= slices.size())    return 0;
    if(dp[i][n]!=1) return dp[i][n];

    return dp[i][n] = max(solve(i+1, n, slices), solve(i+2, n-1, slices)+slices[i]);
}

int main(){
    vector<int> slices = {1,2,3,4,5,6};
    int n = slices.size();
    int dontpickOthslice = solve(1, n/3, slices); 
    
    memset(dp, -1, sizeof(dp));
    slices[n-1] = 0;
    int pick0thslice = solve(0, n/3, slices);
    cout << max(pick0thslice, dontpickOthslice) << endl;
    return 0;
}