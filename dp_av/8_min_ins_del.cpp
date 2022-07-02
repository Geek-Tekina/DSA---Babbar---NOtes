#include <iostream>
#include <string>
using namespace std;

int solve(string x, string y){
    int m = x.size();
    int n = y.size();
    
    int t[m+1][n+1];
    for(int i=0 ; i<=m ; ++i)
        for(int j=0 ; j<=n ; ++j){
            if(i == 0 || j == 0)    t[i][j] = 0;
            else if(x[i-1] == y[j-1])
                t[i][j] = 1 + t[i-1][j-1];
            else 
                t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    
    int lcs = t[m][n];
    return (m-lcs) + (n-lcs);
}

int main(){
    cout << solve("heap", "pea") << endl;
    return 0;
}