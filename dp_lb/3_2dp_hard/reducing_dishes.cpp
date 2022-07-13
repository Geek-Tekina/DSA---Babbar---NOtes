#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;

int t[6][6];
int solve(vi& s, int n, int index){
    if(n == s.size())   return 0;
    return max( solve(s, n+1, index), solve(s, n+1, index+1) + index*s[n] );
}

int memo(vi& s, int n, int index){
    if(n == s.size()) {
        t[n][index] = 0;
        return 0;
    }

    int ans1; 
    if(t[n+1][index] != -1)
       ans1 = t[n+1][index];
    else    ans1 = memo(s, n+1, index); 
    
    int ans2; 
    if(t[n+1][index+1] != -1)
       ans2 = t[n+1][index+1] + (index*s[n]);
    else    ans2 = memo(s, n+1, index+1) + (index*s[n]); 
    
    t[n][index] = max(ans1, ans2);
    return t[n][index];
}

int main(){
    vi s = {-1,-8,0,5,-9};
    sort(s.begin(), s.end());

    for(int i=0; i<=s.size(); ++i)
        for(int j=0; j<=s.size(); ++j)
            t[i][j] = -1;

    // cout << solve(s, 0, 1) << endl;  
    cout << memo(s, 0, 1) << endl; 
    // 2d print t
    for(int i=0; i<=s.size(); ++i){
        for(int j=0; j<=s.size(); ++j)
            cout << t[i][j] << " ";
        cout << endl;
    }
    return 0;
}