#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<vector<int>> vvi;

int maxHeight(vvi& cuboids) {
    for(int i=0 ; i<cuboids.size() ; ++i) 
        sort(cuboids[i].begin(), cuboids[i].end());
    
    sort(cuboids.begin(), cuboids.end(), [](const vector<int>& a, const vector<int>& b) {
            if(a[0] == b[0]){
            if(a[1] == b[1])
                return a[2] > b[2];
            return a[1] > b[1];
        }
        return a[0] > b[0];
    });
    int dp[cuboids.size()];
    int ans = 0;
    for(int i=0 ; i<cuboids.size() ; ++i) {
        dp[i] = cuboids[i][2];
        for(int j=0 ; j<i ; ++j) {
            if(cuboids[j][1] >= cuboids[i][1] && cuboids[j][2] >= cuboids[i][2]) {
                dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
            }
        }
        ans = max(ans, dp[i]);
    }

    return ans;
}

int main(){
    vvi cuboids = {{50,45,20},{95,37,53},{45,23,12}};
    cout << maxHeight(cuboids) << endl;
    return 0;
}