#include <iostream>
#include <math.h>
#include <climits>
using namespace std;

int solve(int left, int n){
    if(left == 0)   return 0;
    else if(n == 0)      return INT_MAX - 1;

    if(left >= n*n){
        return min(solve(left, n-1), solve(left-(n*n), n) + 1);
    } else {
        return solve(left, n-1);
    }
}

int dp(int left, int n){
    int t[n+1][left+1];
    // 2d loop
    for(int i=0; i<=n; ++i){
        for(int j=0; j<=left; ++j){
            if(j == 0) t[i][j] = 0;
            else if(i == 0) t[i][j] = INT_MAX - 1;
            else if(i*i <= j){
                t[i][j] = min(t[i-1][j], t[i][j-i*i] + 1);
            } else {
                t[i][j] = t[i-1][j];
            }
        }
    }
    return t[n][left];
}

int MinSquares(int n){
    int x = sqrt(n);
    // cout << x << endl;
    return dp(n, x);
}

int main(){
    cout << MinSquares(100);
    return 0;
}