#include <iostream>
#include <vector>
#include <stack>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int solve(int n, int k, vi &prices, vi &nge, vvi &dp){
    if(n == prices.size() || k == 0)    return dp[n][k] = 0;
    if(dp[n][k] != -1)  return dp[n][k];
    if(nge[n] == -1){
        return dp[n][k] = solve(n+1, k, prices, nge, dp);    
    } else {
        return dp[n][k] = max(solve(n+1, k, prices, nge, dp), solve(nge[n], k-1, prices, nge, dp) + prices[nge[n]] - prices[n]);
    }
}

int maxPrices(int k, vi &prices){
    stack<int> st;
    // wrong answer bec we have to find next greatest element
    vi nge(prices.size(), -1);
    for(int i=0; i<prices.size(); i++){
        while(!st.empty() && prices[st.top()] < prices[i]){
            nge[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    // print nge
    for(int i=0; i<nge.size(); i++){
        cout << prices[nge[i]] << " ";
    }
    vvi dp(prices.size()+1, vi(k+1, -1));
    int ans = solve(0, k, prices, nge, dp);
    for(int n=0 ; n<=prices.size() ; ++n){
        for(int K=0 ; K<=k ; ++K){
            cout << dp[n][K] << " ";
        }
        cout << endl;
    }
    return ans;
}

int main(){
    // vi prices = {3, 2, 6, 5, 0, 3};  // 7
    vi prices = {6, 1, 3, 2, 4, 7};     // 7
    int k=2;
    cout << maxPrices(k, prices) << endl;
    return 0;
}