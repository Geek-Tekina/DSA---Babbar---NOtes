#include <iostream>
#include <vector>
#include <string>
using namespace std;

string x = "intention";
string y = "execution";

int solve(int m, int n){
    if(m == 0 || n == 0)    return 0;
    if(x[m-1] == y[n-1])    return 1 + solve(m-1, n-1);
    else    return max(solve(m-1, n), solve(m, n-1));
}   

int dp_subsequence(){
    int t[x.size()+1][y.size()+1];

    for(int i=0; i<=x.size() ; ++i){
        for(int j=0 ; j<=y.size() ; ++j){
            if(i == 0 || j == 0)    t[i][j] = 0;
            else if(x[i-1] == y[j-1])   t[i][j] = 1 + t[i-1][j-1];
            else    t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }
    return t[x.size()][y.size()];
}

int dp_substr(){
    int t[x.size()+1][y.size()+1];
    int mx = 0;

    for(int i=0; i<=x.size() ; ++i){
        for(int j=0 ; j<=y.size() ; ++j){
            if(i == 0 || j == 0)    t[i][j] = 0;
            else if(x[i-1] == y[j-1]){
                t[i][j] = 1 + t[i-1][j-1];
                mx = max(mx, t[i][j]); 
            }
            else    t[i][j] = 0;
        }
    }
    return mx;
}

int main(){
    cout << dp_subsequence() << endl;
    cout << dp_substr() << endl;
    return 0;
}