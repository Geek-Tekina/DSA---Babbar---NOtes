#include <iostream>
#include <vector>
using namespace std;

int val[] = {60, 100, 120};
int wt[] = {10, 20, 30};
int W = 50;
int n = sizeof(val) / sizeof(val[0]);

int solve(int n, int w){
    if(n==0 || w==0)    return 0;

    if(wt[n-1] <= w ){
        return max(val[n-1] + solve(n-1, w - wt[n-1]), solve(n-1, w));
    } else {
        return solve(n-1, w);
    }
}

int dp(){
    int **t;
    t = new int*[n+1];
    for(int i=0 ; i<=n ; ++i)
        t[i] = new int[W+1];

    for(int i=0 ; i<=n ; ++i)
        for(int w=0 ; w<=W ; ++w){
            if(i==0 || w==0)    t[i][w] = 0;
            else if(wt[i-1] <= w ){
                t[i][w] = max(val[i-1] + t[i-1][w - wt[i-1]], t[i-1][w]);
            } else {
                t[i][w] = t[i-1][w];
            }
        }
    return t[n][W];
}

int main(){
    // cout << solve(n, W);
    cout << dp();
    return 0;
}