#include <iostream>
#include <vector>
using namespace std;

int val[] = {1,5,18,9,10,17,17,20};
int wt[] = {1,2,3,4,5,6,7,8};
int W = 8;
int n = sizeof(val) / sizeof(val[0]);

int solve(int n, int w){
    if(n==0 || w==0)    return 0;

    if(wt[n-1] <= w ){
        return max(val[n-1] + solve(n, w - wt[n-1]), solve(n-1, w));
    } else {
        return solve(n-1, w);
    }
}

int dp_subsequence(){
    int **t;
    t = new int*[n+1];
    for(int i=0 ; i<=n ; ++i)
        t[i] = new int[W+1];

    for(int i=0 ; i<=n ; ++i)
        for(int w=0 ; w<=W ; ++w){
            if(i==0 || w==0)    t[i][w] = 0;
            else if(wt[i-1] <= w ){
                t[i][w] = max(val[i-1] + t[i][w - wt[i-1]], t[i-1][w]);
            } else {
                t[i][w] = t[i-1][w];
            }
        }
    return t[n][W];
}

int main(){
    // cout << solve(n, W);
    cout << dp_subsequence();
    return 0;
}