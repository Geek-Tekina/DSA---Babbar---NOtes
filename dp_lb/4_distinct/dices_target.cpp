#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define mod 1000000007

int solve(int n, int left, int k, vector<vector<int>> &t) {
    if(n == 0 && left == 0) return t[n][left] = 1;
    if(n == 0 || left < 0 ) return t[n][0] = 0;

    if(t[n][left] != -1) return t[n][left];
    int ways=0;
    for(int i=1 ; i<=k ; ++i){
        ways = (ways + solve(n-1, left-i, k, t)) % mod;
    }
    t[n][left] = (ways % mod);
    return t[n][left];
}

int main(){
    int n=30;
    int k=30;
    int target=500;
    vector<vector<int>> t(n+1, vector<int>(target+1, -1));
    cout << solve(n, target, k, t) << endl;
    return 0;
}
