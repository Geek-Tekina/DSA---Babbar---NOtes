#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
typedef vector<vector<int>> vvi;

int solve(vvi &env, int prev, int curr, vvi& t) {
    if(curr == env.size()) 
        return 0;
    
    if(t[prev][curr] != -1) 
        return t[prev][curr];

    int pick=0;
    if(env[curr][0] > env[prev][0] && env[curr][1] > env[prev][1]) {
        pick = 1 + solve(env, curr, curr+1, t);
    }
    int dontpick = solve(env, prev, curr+1);
    return t[prev][curr] = max(pick, dontpick, t);
}

int main(){
    vvi env = {{1,1},{2,2},{1,1}};
    env.push_back({INT_MIN, INT_MIN});
    vvi t(env.size(), vector<int>(env.size(), -1));
    sort(env.begin(), env.end(), [](vector<int>& a, vector<int>& b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    });
    cout << solve(env, 0, 1, t) << endl;
    return 0;
}