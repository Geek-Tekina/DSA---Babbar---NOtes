#include <iostream>
#include <vector>
using namespace std;

// min count stairs is same just add cost and find min
int dp2(int []cost,int n){
    int n = cost.size();
    int t[n+1];
    t[0] = cost[0];
    t[1] = cost[1];
    for(int i=2 ; i<=n ; ++i)
        t[i] = min(t[i-1], t[i-2]) + cost[i];
    
    // we can go to nth floor from n-1th floor or n-2th floor w/o having extra cost
    // hence t[n] is not taken
    return min(t[n-2], t[n-1]);
}

int solve(int n){
    if(n == 0)  return 1;
    else if(n < 0)  return 0;

    return solve(n-1) + solve(n-2);
}

int dp(int n){
    int t[n+1];
    t[0] = 1;
    t[1] = 1;

    for(int i=2 ; i <=n ; ++i){
        t[i] = t[i-1] + t[i-2];
    }
    return t[n];
}

int main(){
    int n = 44;
    cout << dp(n) << endl;
    cout << solve(n) << endl;
    return 0;
}